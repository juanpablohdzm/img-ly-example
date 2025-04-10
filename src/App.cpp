//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//

#include "App.h"
#include <iostream>
#include <SDL3/SDL.h>

#include "components/PlayerController.h"
#include "components/Window.h"
#include "components/WindowBackground.h"
#include "components/commands/QuitCommand.h"

int App::run() {

    App instance;

    instance.initialize();
    instance.mainLoop();
    instance.destroy();

    return 0;
}

void App::initialize() {
    registry = std::make_unique<entt::registry>();

    window = std::make_unique<Window>("Example", 800, 600);
    windowBackground = std::make_unique<WindowBackground>(registry.get(), window.get());

    quitCommand = std::make_unique<QuitCommand>(*this);

    playerController = std::make_unique<PlayerController>();
    playerController->addQuitEvent(this, &App::quit);
    playerController->addKeyCommand(SDLK_ESCAPE, quitCommand.get());
}

void App::mainLoop() {

    // Main event and render loop
    isRunning = true;

    Uint64 currentTime = SDL_GetTicks();
    Uint64 lastTime = 0.0f;
    float deltaTime = 0.0f;

    while (!shouldStop()) {

        lastTime = currentTime;
        currentTime = SDL_GetTicks();

        deltaTime =(currentTime - lastTime)/1000.0f;


        playerController->run();
        window->clearWindow();
        windowBackground->update(deltaTime);

        window->presentRender();
    }
}

bool App::shouldStop() const {
    return !isRunning;
}

void App::quit() {
    isRunning = false;
}

void App::destroy() const {
    // Clean up resources
    SDL_Quit();
}

