//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#include "GameManager.h"

#include <iostream>

#include "Window.h"
#include "ECSEntities/PlayerCharacter.h"
#include "ECSSystems/SpawnEnemySystem.h"
#include "ECSSystems/UpdateEnemyTargetSystem.h"
#include "ECSSystems/UpdateEnemyVelocitySystem.h"
#include "ECSSystems/UpdateGunTransformSystem.h"
#include "ECSSystems/WindowGuardSystem.h"
#include "ui/Canvas.h"
#include "ui/Sprite.h"
#include "ui/menus/GameHud.h"
#include "ui/menus/MainMenu.h"


GameManager::GameManager() : playerController(nullptr), currentState(GameState::DEFAULT){
}



void GameManager::initialize(PlayerController *pc) {
    if (!pc) {
        throw std::runtime_error("PlayerController is null");
    }

    auto* instance = getInstance();
    instance->playerController = pc;

    instance->mainMenuCanvas = std::make_unique<MainMenu>(instance->playerController);
    instance->mainMenuCanvas->initialize();
    instance->gameHud = std::make_unique<GameHud>(instance->playerController);
    instance->gameHud->initialize();

    GameManager::setCurrentState(GameState::MAIN_MENU);

}

GameManager::~GameManager() {

}

void GameManager::update(float dt) {
    auto* instance = getInstance();
    if (getCurrentState() == GameState::MAIN_MENU) {
        instance->mainMenuCanvas->update(dt);
    } else if (getCurrentState() == GameState::PLAYING) {
        instance->gameHud->update(dt);
        SpawnEnemySystem::update(dt);
        UpdateEnemyTargetSystem::update(dt);
        UpdateEnemyVelocitySystem::update(dt);
        WindowGuardSystem::update(dt);
        UpdateGunTransformSystem::update(dt);
    }
}

void GameManager::setCurrentState(GameState state) {
    auto* instance = getInstance();

    if (instance->currentState == state) {
        return;
    }

    switch (state) {
        case GameState::DEFAULT:
            break;
        case GameState::MAIN_MENU:
            break;
        case GameState::PLAYING:
            instance->setupPlayState();
            break;
        default: ;
    }
    instance->currentState = state;
}

void GameManager::setupPlayState() {
    playerCharacter = std::make_unique<PlayerCharacter>(
        "resource/Hangar/Armor_Icon.png",
        65,
        65,
        Position(Window::getWidth() * 0.5f, Window::getHeight() * 0.5f),
        100.0f,
        playerController
    );
}
