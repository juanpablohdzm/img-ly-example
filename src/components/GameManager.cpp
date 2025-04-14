//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#include "GameManager.h"

#include <iostream>

#include "Window.h"
#include "ui/Canvas.h"
#include "ui/menus/MainMenu.h"


GameManager::GameManager() : playerController(nullptr), mainMenuCanvas(nullptr), currentState(GameState::DEFAULT) {
}

void GameManager::initialize(PlayerController *pc) {
    if (!pc) {
        throw std::runtime_error("PlayerController is null");
    }

    auto* instance = getInstance();
    instance->playerController = pc;

    instance->setCurrentState(GameState::MAIN_MENU);
    instance->mainMenuCanvas = std::make_unique<MainMenu>(instance->playerController);
    instance->mainMenuCanvas->initialize();

}

GameManager::~GameManager() {

}

void GameManager::update(float dt) {
    auto* instance = getInstance();
    if (getCurrentState() == GameState::MAIN_MENU) {
        instance->mainMenuCanvas->update(dt);
    }
}

void GameManager::setCurrentState(GameState state) {
    auto* instance = getInstance();
    instance->currentState = state;
}
