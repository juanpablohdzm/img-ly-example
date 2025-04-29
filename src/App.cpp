//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//

#include "App.h"
#include <iostream>
#include <SDL3/SDL.h>

#include "components/GameManager.h"
#include "components/PlayerController.h"
#include "components/Window.h"
#include "components/WindowBackground.h"
#include "components/ECSSystems/DespawnEntitiesSystem.h"
#include "components/ECSSystems/MoveSystem.h"
#include "components/ECSSystems/SpriteRenderSystem.h"
#include "components/ECSSystems/UpdateSpritePositionSystem.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


App::App() : Singleton<App>() {
    playerController = std::make_unique<PlayerController>();
}

int App::run() {

    App* instance = getInstance();

    instance->initialize();
    instance->mainLoop();

    return 0;
}

void App::exit() {
    App* instance = getInstance();
    instance->quit();
}

void App::initialize() {

    Window::initialize("Example", WINDOW_WIDTH, WINDOW_HEIGHT);
    WindowBackground::initialize();
    GameManager::initialize(playerController.get());

    playerController->addQuitEvent(this, exit);
    playerController->addKeyCallback(SDLK_ESCAPE, this, [](const SDL_Event& event) {
        if (event.type == SDL_EVENT_KEY_DOWN) {
            exit();
        }
    });
}

void App::mainLoop(){

    // Main event and render loop

    Uint64 currentTime = SDL_GetTicks();
    Uint64 lastTime = 0.0f;
    float deltaTime = 0.0f;

    isRunning = true;

    while (isRunning) {

        lastTime = currentTime;
        currentTime = SDL_GetTicks();

        deltaTime = (currentTime - lastTime)/1000.0f;

        Window::clearWindow();
            WindowBackground::update();
            playerController->update();
            MoveSystem::update(deltaTime);
            GameManager::update(deltaTime);
            UpdateSpritePositionSystem::update();
            SpriteRenderSystem::update();
        Window::presentRender();
        DespawnEntitiesSystem::update();
    }

    SDL_Quit();
}

void App::quit(){
    isRunning = false;
}

