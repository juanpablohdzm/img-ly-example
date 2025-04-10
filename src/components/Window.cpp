//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#include "Window.h"

#include <iostream>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>

Window::Window(const char *title, int width, int height, Color color) : color(color), width(width), height(height) {

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
        return;
    }

    // Create an SDL window
    window = SDL_CreateWindow(title,width, height, SDL_WINDOW_OPENGL);
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
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Window::clearWindow() const {
    // Clear the screen to black
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}

void Window::presentRender() const {
    // Present the rendered frame to the window
    SDL_RenderPresent(renderer);
    // Delay to cap the frame rate (approximately 60 FPS)
    SDL_Delay(16);
}
