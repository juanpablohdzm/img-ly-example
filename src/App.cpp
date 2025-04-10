//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//

#include "App.h"
#include <iostream>
#include <SDL3/SDL.h>

#include "components/PlayerController.h"
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

    quitCommand = std::make_unique<QuitCommand>(*this);

    playerController = std::make_unique<PlayerController>();
    playerController->addQuitEvent(this, &App::quit);
    playerController->addKeyCommand(SDLK_ESCAPE, quitCommand.get());
}

void App::mainLoop() {

    // Main event and render loop
    isRunning = true;

    while (!shouldStop()) {
        playerController->run();
        window->clearWindow();
        // Set the drawing color to red and draw a filled rectangle
        /*window->executeRendererAction([](SDL_Renderer* renderer) {
            SDL_FRect rect = { 100, 100, 200, 150 };
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
        });*/

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

