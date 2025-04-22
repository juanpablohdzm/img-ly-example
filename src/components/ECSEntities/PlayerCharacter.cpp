//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#include "PlayerCharacter.h"

#include <iostream>

#include "../PlayerController.h"

#include <SDL3/SDL_keycode.h>

#include "../ECSManager.h"
#include "../GameManager.h"
#include "../ECSComponents/GunTag.h"
#include "../ui/Sprite.h"



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

    //Create gun pointer
    auto gunEntity = ECSManager::create();
    ECSManager::emplace<Position>(gunEntity, position);
    ECSManager::emplace<Sprite>(gunEntity, "resource/Hangar/Speed_Icon.png", position, 53 * 0.5f, 64 * 0.5f);
    ECSManager::emplace<GunTag>(gunEntity, GunTag());

    controller->addKeyCallback(SDLK_W, this, [this](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            for (auto [entity, vel] : ECSManager::view<Velocity, PlayerTag>().each()) {
                vel.dy = event.type == SDL_EVENT_KEY_DOWN ? -1 : 0;
            }
        }
    });
    controller->addKeyCallback(SDLK_S, this, [this](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            for (auto [entity, vel] : ECSManager::view<Velocity, PlayerTag>().each()) {
                vel.dy = event.type == SDL_EVENT_KEY_DOWN ? 1 : 0;
            }
       }
    });
    controller->addKeyCallback(SDLK_A, this, [this](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            for (auto [entity, vel] : ECSManager::view<Velocity, PlayerTag>().each()) {
                vel.dx = event.type == SDL_EVENT_KEY_DOWN ? -1 : 0;
            }
       }
    });
    controller->addKeyCallback(SDLK_D, this, [this](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            for (auto [entity, vel] : ECSManager::view<Velocity, PlayerTag>().each()) {
                vel.dx = event.type == SDL_EVENT_KEY_DOWN ? 1 : 0;
            }
       }
    });
}

PlayerCharacter::~PlayerCharacter() {
    if (!controller) {
        return;
    }
    controller->clearKeyCallback(SDLK_W,this);
    controller->clearKeyCallback(SDLK_S,this);
    controller->clearKeyCallback(SDLK_A,this);
    controller->clearKeyCallback(SDLK_D,this);
}