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
#include "components/ECSSystems/BulletCollisionSystem.h"
#include "components/ECSSystems/EnemyCollisionSystem.h"
#include "components/ECSComponents/Position.h"
#include "components/ui/Canvas.h"
#include "components/ui/menus/GameHud.h"
#include "components/ui/menus/MainMenu.h"
#include "components/ui/menus/GameOverMenu.h"


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

    instance->gameOverCanvas = std::make_unique<GameOverMenu>(instance->playerController);
    instance->gameOverCanvas->initialize();

    setCurrentState(GameState::MAIN_MENU);

}

GameManager::~GameManager() {

}

void GameManager::update(float dt) {
    auto* instance = getInstance();
    if (getCurrentState() == GameState::MAIN_MENU) {
        instance->mainMenuCanvas->update();
    } else if (getCurrentState() == GameState::PLAYING) {

        if (getCurrentWaveState() == WaveState::ACTIVE) {
            SpawnEnemySystem::update(dt);
                UpdateEnemyTargetSystem::update();
                UpdateEnemyVelocitySystem::update();
                EnemyCollisionSystem::update();
        }

        UpdateGunTransformSystem::update();
            BulletCollisionSystem::update();

        WindowGuardSystem::update();
        DespawnBulletSystem::update();

        instance->gameHud->update();
    } else if (getCurrentState() == GameState::GAME_OVER) {
        instance->gameOverCanvas->update();
    }
}

void GameManager::setCurrentState(GameState state) {
    auto* instance = getInstance();

    if (instance->currentState == state) {
        return;
    }

    instance->currentState = state;
    switch (state) {
        case GameState::DEFAULT:
            break;
        case GameState::MAIN_MENU:
            break;
        case GameState::PLAYING:
            instance->setupPlayState();
            break;
        case GameState::GAME_OVER: {

            PlayerController::toggleCursor(true);
            //TODO: Improve clean up gameplay state
            for (auto [entity] : ECSManager::view<EnemyTag>(entt::exclude_t<DespawnTag>()).each()) {
                ECSManager::emplace<DespawnTag>(entity);
            }
            for (auto [entity] : ECSManager::view<BulletTag>(entt::exclude_t<DespawnTag>()).each()) {
                ECSManager::emplace<DespawnTag>(entity);
            }
            instance->playerCharacter.reset();
            break;
        }
        default: ;
    }
}

void GameManager::setCurrentWaveState(WaveState state) {
    auto* instance = getInstance();
    if (getCurrentState() != GameState::PLAYING || state == getCurrentWaveState()) {
        return;
    }

    instance->currentWaveState = state;
    switch (state) {
        case WaveState::PREPARING:
            instance->currentWave++;
            instance->enemyCount = 0;
            instance->enemyKilled = 0;
            instance->gameHud->updateWave(getCurrentWave());
            instance->waveTimer.start(3000, []() {
                setCurrentWaveState(WaveState::ACTIVE);
                std::cout << "Wave started!" << std::endl;
            });
            break;
        case WaveState::ACTIVE:
            break;
        case WaveState::ENDING:
            setCurrentWaveState(WaveState::PREPARING);
            break;
        default: ;
    }
}

void GameManager::addScorePoint(int amount) {
    auto* instance = getInstance();
    if (getCurrentState() != GameState::PLAYING) {
        return;
    }

    instance->currentScore += amount;
    instance->gameHud->updateScore(instance->currentScore);

    instance->enemyKilled += amount;
    if (getEnemyCount() >= getEnemySpawnBatchLimit() * getCurrentWave() &&
        instance->enemyKilled >= getEnemyCount()) {
        setCurrentWaveState(WaveState::ENDING);
    }
}

void GameManager::onPlayerHit() {
    if (getCurrentState() != GameState::PLAYING) {
        return;
    }
    setCurrentState(GameState::GAME_OVER);
}

uint GameManager::getCurrentWave() {
    const auto* instance = getInstance();
    if (getCurrentState() != GameState::PLAYING) {
        return 0;
    }

    return instance->currentWave;
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
    setCurrentWaveState(WaveState::PREPARING);
}
