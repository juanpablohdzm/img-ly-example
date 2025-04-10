//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#include "GameManager.h"

#include <iostream>

GameManager::GameManager(entt::registry *registry, Window *window, PlayerController *pc)
    : window(window), registry(registry), playerController(pc), currentState(GameState::DEFAULT) {
    if (!window) {
        throw std::runtime_error("Window is null");
    }
    if (!registry) {
        throw std::runtime_error("Registry is null");
    }
    if (!pc) {
        throw std::runtime_error("PlayerController is null");
    }

    setCurrentState(GameState::MAIN_MENU);
}

void GameManager::update(float dt) {
}

void GameManager::setCurrentState(GameState state) {
    if (currentState == state) {
        return;
    }

    currentState = state;
    switch (currentState) {
        case GameState::DEFAULT:
            std::cout << "GameManager: State changed to DEFAULT" << std::endl;
            break;
        case GameState::MAIN_MENU:
            initMainMenu();
            break;
        case GameState::PLAYING:
            break;
        default: ;
    }
}

void GameManager::initMainMenu() {

}
