//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#include "GameManager.h"

#include <iostream>

#include "Window.h"
#include "ui/Canvas.h"
#include "ui/menus/MainMenu.h"

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

    mainMenuCanvas = std::make_unique<MainMenu>(window, playerController, this);
}

GameManager::~GameManager() {

}

void GameManager::update(float dt) {
    std::cout << (int)currentState << std::endl;
    if (currentState == GameState::MAIN_MENU) {
        mainMenuCanvas->update(dt);
    }
}

void GameManager::initialize() {
    mainMenuCanvas->initialize();
}

void GameManager::setCurrentState(GameState state) {
    currentState = state;
}
