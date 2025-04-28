//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#include "PlayerCharacter.h"

#include <components/ECSComponents/Collider.h>
#include <components/ECSComponents/Tags/DespawnTag.h>
#include <SDL3/SDL_keycode.h>

#include "components/PlayerController.h"
#include "components/ECSManager.h"
#include "components/GameManager.h"
#include "components/ECSComponents/Tags/GunTag.h"
#include "components/ECSComponents/Tags/BulletTag.h"
#include "components/ECSComponents/Tags/PlayerTag.h"
#include "components/ECSComponents/Velocity.h"
#include "components/ECSComponents/WindowGuard.h"
#include "components/ECSComponents/Speed.h"
#include "components/ECSComponents/Position.h"
#include "components/ui/Sprite.h"

PlayerCharacter::PlayerCharacter(
    const char *spritePath,
    float width,
    float height,
    const Position &position,
    float speed,
    PlayerController* controller): controller(controller) {

    //Create player character
    auto entity = ECSManager::create();
    ECSManager::emplace<PlayerTag>(entity, PlayerTag());
    ECSManager::emplace<Position>(entity, position);
    ECSManager::emplace<Velocity>(entity, Velocity());
    ECSManager::emplace<WindowGuard>(entity, width, height);
    ECSManager::emplace<Speed>(entity, speed);
    ECSManager::emplace<Sprite>(entity, spritePath, position, width, height);
    ECSManager::emplace<Collider>(entity, width, height);

    //Create gun pointer
    auto gunEntity = ECSManager::create();
    ECSManager::emplace<Position>(gunEntity, position);
    ECSManager::emplace<Sprite>(gunEntity, "resource/Hangar/Speed_Icon.png", position, 53 * 0.5f, 64 * 0.5f);
    ECSManager::emplace<GunTag>(gunEntity, GunTag());

    controller->addKeyCallback(SDLK_W, this, [](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            for (auto [entity, vel] : ECSManager::view<Velocity, PlayerTag>().each()) {
                vel.value.y = event.type == SDL_EVENT_KEY_DOWN ? -1 : 0;
            }
        }
    });
    controller->addKeyCallback(SDLK_S, this, [](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            for (auto [entity, vel] : ECSManager::view<Velocity, PlayerTag>().each()) {
                vel.value.y = event.type == SDL_EVENT_KEY_DOWN ? 1 : 0;
            }
       }
    });
    controller->addKeyCallback(SDLK_A, this, [](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            for (auto [entity, vel] : ECSManager::view<Velocity, PlayerTag>().each()) {
                vel.value.x = event.type == SDL_EVENT_KEY_DOWN ? -1 : 0;
            }
       }
    });
    controller->addKeyCallback(SDLK_D, this, [](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            for (auto [entity, vel] : ECSManager::view<Velocity, PlayerTag>().each()) {
                vel.value.x = event.type == SDL_EVENT_KEY_DOWN ? 1 : 0;
            }
       }
    });

    controller->addKeyCallback(SDL_BUTTON_LEFT, this, [](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            if (event.type != SDL_EVENT_MOUSE_BUTTON_UP) {
                return;
            }
            Position spawnPosition {glm::vec3(0.0f, 0.0f, 0.0f)};
            for (auto[entity, position] : ECSManager::view<Position, GunTag>().each()) {
                spawnPosition = position;
            }

            const auto mousePosition = PlayerController::getMousePosition();
            const auto mouseDirection  = mousePosition.value - spawnPosition.value;

            auto bulletEntity = ECSManager::create();
            ECSManager::emplace<Position>(bulletEntity, spawnPosition);
            ECSManager::emplace<Velocity>(bulletEntity, Velocity{mouseDirection});
            ECSManager::emplace<Speed>(bulletEntity, 100.0f);
            ECSManager::emplace<BulletTag>(bulletEntity, BulletTag());
            ECSManager::emplace<Sprite>(bulletEntity, "resource/Hangar/Dot_01.png", spawnPosition, 71 * 0.3f, 71 * 0.3f);
            ECSManager::emplace<Collider>(bulletEntity, 71 * 0.3f, 71 * 0.3f);
        }
    });
}

PlayerCharacter::~PlayerCharacter() {
    for (auto [entity] : ECSManager::view<PlayerTag>().each()) {
        ECSManager::emplace<DespawnTag>(entity);
    }
    for (auto [entity] : ECSManager::view<GunTag>().each()) {
        ECSManager::emplace<DespawnTag>(entity);
    }

    if (!controller) {
        return;
    }
    controller->clearKeyCallback(SDLK_W,this);
    controller->clearKeyCallback(SDLK_S,this);
    controller->clearKeyCallback(SDLK_A,this);
    controller->clearKeyCallback(SDLK_D,this);
    controller->clearKeyCallback(SDL_BUTTON_LEFT,this);
}