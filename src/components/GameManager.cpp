//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#include "GameManager.h"

#include <iostream>

#include "Window.h"
#include "ui/Button.h"
#include "ui/Canvas.h"

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

    playButton = std::make_unique<Button>(
        window->getRenderer(),
        "resource/Buttons/BTNs/Play_BTN.png",
        "resource/Buttons/BTNs_Active/Play_BTN.png",
        nullptr,
        Position(100, 100),
        210*0.33f, 210*0.33f,
        [this]() {
            std::cout << "Play button clicked" << std::endl;
        }
    );
    quitButton = std::make_unique<Button>(
        window->getRenderer(),
        "resource/Buttons/BTNs/Close_BTN.png",
        "resource/Buttons/BTNs_Active/Close_BTN.png",
        nullptr,
        Position(100, 300),
        210* 0.33f, 210 * 0.33f,
        [this]() {
            std::cout << "Quit button clicked" << std::endl;
        });
    mainMenuCanvas = std::make_unique<Canvas>(window, playerController);
    mainMenuCanvas->addChild(playButton.get());
    mainMenuCanvas->addChild(quitButton.get());
}

GameManager::~GameManager() {

}

void GameManager::update(float dt) {
    window->executeRendererAction([&, dt](SDL_Renderer* renderer) {
        mainMenuCanvas->update(dt);
    });
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
