//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#include "GameManager.h"

#include <iostream>

#include "components/Window.h"
#include "components/ECSEntities/PlayerCharacter.h"
#include "components/ECSSystems/DespawnBulletSystem.h"
#include "components/ECSSystems/SpawnEnemySystem.h"
#include "components/ECSSystems/UpdateEnemyTargetSystem.h"
#include "components/ECSSystems/UpdateEnemyVelocitySystem.h"
#include "components/ECSSystems/UpdateGunTransformSystem.h"
#include "components/ECSSystems/WindowGuardSystem.h"
#include "components/ECSSystems/CollisionSystem.h"
#include "components/ECSComponents/Position.h"
#include "components/ui/Canvas.h"
#include "components/ui/menus/GameHud.h"
#include "components/ui/menus/MainMenu.h"


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
        instance->mainMenuCanvas->update();
    } else if (getCurrentState() == GameState::PLAYING) {
        instance->gameHud->update();
        SpawnEnemySystem::update(dt);
        UpdateEnemyTargetSystem::update();
        UpdateEnemyVelocitySystem::update();
        WindowGuardSystem::update();
        UpdateGunTransformSystem::update();
        DespawnBulletSystem::update();
        CollisionSystem::update();
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
        Position(glm::vec3(Window::getWidth() * 0.5f, Window::getHeight() * 0.5f, 0.0f)),
        100.0f,
        playerController
    );

    PlayerController::toggleCursor(false);
}
