//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#include "GameManager.h"

#include <iostream>

#include "Window.h"
#include "./ui/Button.h"

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
    window->executeRendererAction([](SDL_Renderer* renderer) {

        const std::string defaultPath = "resource/Buttons/BTNs/Play_BTN.png";
        const std::string hoverPath = "resource/Buttons/BTNs_Active/Play_BTN.png";

        Button button(
            renderer,
            defaultPath.c_str(),
            hoverPath.c_str(),
            nullptr,
            100, 100,
            200, 50
        );
        button.render();
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
