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

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


App & App::getInstance() {
    static App instance;
    return instance;
}

int App::run() {

    App& instance = getInstance();

    instance.initialize();
    instance.mainLoop();

    return 0;
}

void App::exit() {
    App& instance = getInstance();
    instance.quit();
}

void App::initialize() {
    registry = std::make_unique<entt::registry>();

    window = std::make_unique<Window>("Example", WINDOW_WIDTH, WINDOW_HEIGHT);
    windowBackground = std::make_unique<WindowBackground>(registry.get(), window.get());


    playerController = std::make_unique<PlayerController>();
    playerController->addQuitEvent(this, &App::quit);
    playerController->addKeyCallback(SDLK_ESCAPE, this, &App::quit);

    gameManager = std::make_unique<GameManager>(registry.get(), window.get(), playerController.get());
    gameManager->initialize();
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

        window->clearWindow();

        playerController->run();
        windowBackground->update(deltaTime);
        gameManager->update(deltaTime);

        window->presentRender();
    }

    SDL_Quit();
}

void App::quit(const SDL_Event& event) {
    quit();
}

void App::quit(){
    isRunning = false;
}

