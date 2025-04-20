//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#include "PlayerCharacter.h"

#include <iostream>

#include "../PlayerController.h"

#include <SDL3/SDL_keycode.h>

#include "../ECSManager.h"
#include "../GameManager.h"
#include "../ui/Sprite.h"



PlayerCharacter::PlayerCharacter(
    const char *spritePath,
    float width,
    float height,
    const Position &position,
    float speed,
    PlayerController* controller) {
    setController(controller);
    entity = ECSManager::create();
    ECSManager::emplace<PlayerTag>(entity, PlayerTag());
    ECSManager::emplace<Position>(entity, position);
    ECSManager::emplace<Velocity>(entity, Velocity());
    ECSManager::emplace<WindowGuard>(entity, width, height);
    ECSManager::emplace<Speed>(entity, speed);
    ECSManager::emplace<Sprite>(entity, spritePath, position, width, height);
}

void PlayerCharacter::setController(PlayerController* controller) {
    this->controller = controller;
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

void PlayerCharacter::initialize() {

    controller->addKeyCallback(SDLK_W, this, [this](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            direction.dy = event.type == SDL_EVENT_KEY_DOWN ? -1 : 0;
        }
    });
    controller->addKeyCallback(SDLK_S, this, [this](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            direction.dy = event.type == SDL_EVENT_KEY_DOWN ? 1 : 0;
       }
    });
    controller->addKeyCallback(SDLK_A, this, [this](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            direction.dx = event.type == SDL_EVENT_KEY_DOWN ? -1 : 0;
       }
    });
    controller->addKeyCallback(SDLK_D, this, [this](const SDL_Event& event) {
        if (GameManager::getCurrentState() == GameState::PLAYING) {
            direction.dx = event.type == SDL_EVENT_KEY_DOWN ? 1 : 0;
       }
    });
}

void PlayerCharacter::update(float dt) {
    for (auto [entity, vel, speed] : ECSManager::view<Velocity, Speed, PlayerTag>().each()) {
        const float magnitude = sqrt(direction.dx * direction.dx + direction.dy * direction.dy);
        if (magnitude > 0) {
            direction.dx /= magnitude;
            direction.dy /= magnitude;
        }
        vel.dx = direction.dx * speed.value;
        vel.dy = direction.dy * speed.value;
    }
}