//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#include "GameManager.h"

#include <iostream>

#include "Window.h"
#include "characters/PlayerCharacter.h"
#include "ui/Canvas.h"
#include "ui/Sprite.h"
#include "ui/menus/GameHud.h"
#include "ui/menus/MainMenu.h"


GameManager::GameManager() : playerController(nullptr), currentState(GameState::DEFAULT), mainMenuCanvas(nullptr) {
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
    instance->gameHud = std::make_unique<GameHud>(instance->playerController);
    instance->gameHud->initialize();
    instance->playerCharacter = std::make_unique<PlayerCharacter>(
        "resource/Hangar/Armor_Icon.png",
        65,
        65,
        Position(Window::getWidth() * 0.5f, Window::getHeight() * 0.5f),
        50.0f,
        instance->playerController
    );
    instance->playerCharacter->initialize();
    instance->gameHud->addChild(instance->playerCharacter->getSprite());
}

GameManager::~GameManager() {

}

void GameManager::update(float dt) {
    auto* instance = getInstance();
    if (getCurrentState() == GameState::MAIN_MENU) {
        instance->mainMenuCanvas->update(dt);
    } else if (getCurrentState() == GameState::PLAYING) {
        instance->gameHud->update(dt);
        instance->playerCharacter->update(dt);
    }
}

void GameManager::setCurrentState(GameState state) {
    auto* instance = getInstance();
    instance->currentState = state;
}
