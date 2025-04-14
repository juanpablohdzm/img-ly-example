//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#include "Window.h"

#include <iostream>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>


Window::Window() : Singleton<Window>(), color({0,0,0,255}), width(800), height(600) {
}

void Window::initialize(const char *title, int width, int height,const Color& color){

    auto* instance = getInstance();
    instance->color = color;
    instance->width = width;
    instance->height = height;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
        return;
    }

    // Create an SDL window
    instance->window = SDL_CreateWindow(title,width, height, SDL_WINDOW_OPENGL);
    if (!instance->window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        return;
    }

    // Create a renderer for the window
    instance->renderer = SDL_CreateRenderer(instance->window, nullptr);
    if (!instance->renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(instance->window);
        SDL_Quit();
    }
}

void Window::clearWindow() {
    // Clear the screen to black

    const auto* instance = getInstance();
    SDL_SetRenderDrawColor(instance->renderer, instance->color.r, instance->color.g, instance->color.b, instance->color.a);
    SDL_RenderClear(instance->renderer);
}

void Window::presentRender() {
    // Present the rendered frame to the window
    const auto* instance = getInstance();
    SDL_RenderPresent(instance->renderer);
    // Delay to cap the frame rate (approximately 60 FPS)
    SDL_Delay(16);
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}