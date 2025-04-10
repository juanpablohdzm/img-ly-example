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

    // Initialize SDL3 (video subsystem)
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
        return;
    }

    // Create an SDL window
    window = SDL_CreateWindow("SDL3 Window Test",800, 600, SDL_WINDOW_OPENGL);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        return;
    }

    // Create a renderer for the window
    renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

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
        clearRender();
    }
}

void App::clearRender() const {
    // Clear the screen to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Set the drawing color to red and draw a filled rectangle
    SDL_FRect rect = { 100, 100, 200, 150 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    // Present the rendered frame to the window
    SDL_RenderPresent(renderer);

    // Delay to cap the frame rate (approximately 60 FPS)
    SDL_Delay(16);
}

bool App::shouldStop() const {
    return !isRunning;
}

void App::quit() {
    isRunning = false;
}

void App::destroy() const {
    // Clean up resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

