//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#include "PlayerCharacter.h"

#include <iostream>

#include "../PlayerController.h"

#include <SDL3/SDL_keycode.h>

#include "../ECSManager.h"
#include "../GameManager.h"



PlayerCharacter::PlayerCharacter(
    const char *spritePath,
    float width,
    float height,
    const Position &position,
    float speed,
    PlayerController* controller) :
    Character(spritePath,
            width,
            height,
            position),
    speed(speed) {
    setController(controller);
    ECSManager::emplace<PlayerTag>(getEntity(), PlayerTag());
    ECSManager::emplace<Velocity>(getEntity(), Velocity());
    ECSManager::emplace<WindowGuard>(getEntity(), width, height);
    ECSManager::emplace<Speed>(getEntity(), speed);
}

PlayerCharacter::~PlayerCharacter() {
    PlayerController* playerController = getController();
    if (!playerController) {
        return;
    }
    playerController->clearKeyCallback(SDLK_W,this);
    playerController->clearKeyCallback(SDLK_S,this);
    playerController->clearKeyCallback(SDLK_A,this);
    playerController->clearKeyCallback(SDLK_D,this);
}

void PlayerCharacter::initialize() {
    PlayerController* controller = getController();
    ECSManager::emplace<Sprite*>(getEntity(), getSprite());

    controller->addKeyCallback(SDLK_W, this, [this](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            velocity.dy = event.type == SDL_EVENT_KEY_DOWN ? -1 : 0;
        }
    });
    controller->addKeyCallback(SDLK_S, this, [this](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            velocity.dy = event.type == SDL_EVENT_KEY_DOWN ? 1 : 0;
       }
    });
    controller->addKeyCallback(SDLK_A, this, [this](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            velocity.dx = event.type == SDL_EVENT_KEY_DOWN ? -1 : 0;
       }
    });
    controller->addKeyCallback(SDLK_D, this, [this](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            velocity.dx = event.type == SDL_EVENT_KEY_DOWN ? 1 : 0;
       }
    });
}

void PlayerCharacter::update(float dt) {
    for (auto [entity, vel] : ECSManager::view<Velocity, PlayerTag>().each()) {
        const float magnitude = sqrt(velocity.dx * velocity.dx + velocity.dy * velocity.dy);
        if (magnitude > 0) {
            velocity.dx /= magnitude;
            velocity.dy /= magnitude;
        }
        vel.dx = velocity.dx * speed;
        vel.dy = velocity.dy * speed;
    }
}