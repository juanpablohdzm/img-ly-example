//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#include "Button.h"

#include <stdexcept>
#include <string>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>
#include <__filesystem/operations.h>

#include "../Window.h"

namespace fs = std::filesystem;

#define CLICK_DELAY_MS 200

Button::Button(
        const char *defaultImagePath,
        const char *hoverImagePath,
        const char *clickedImagePath,
        const Position& position,
        int width, int height)
        : Widget(position, width, height){

        if (!defaultImagePath) {
                throw std::invalid_argument("Default image path is null");
        }

        defaultImageTexture = loadTexture(defaultImagePath);

        if (hoverImagePath) {
            hoverImageTexture = loadTexture(hoverImagePath);
        }
        if (clickedImagePath) {
            clickedImageTexture = loadTexture(clickedImagePath);
        }

        currentTexture = defaultImageTexture;
}

Button::~Button(){

        if (defaultImageTexture) {
                SDL_DestroyTexture(defaultImageTexture);
        }
        if (hoverImageTexture) {
                SDL_DestroyTexture(hoverImageTexture);
        }
        if (clickedImageTexture) {
                SDL_DestroyTexture(clickedImageTexture);
        }
}

void Button::render(){

        const SDL_FRect fButtonRect = {
                static_cast<float>(rect.x),
                static_cast<float>(rect.y),
                static_cast<float>(getWidth()),
                static_cast<float>(getHeight())
        };
        SDL_RenderTexture(Window::getRenderer(), currentTexture, nullptr, &fButtonRect);
}

void Button::onHoverEnter() {

        if (hoverImageTexture) {
                currentTexture = hoverImageTexture;
        }
}

void Button::onHoverExit() {

        currentTexture = defaultImageTexture;
}

void Button::click() {

        if (clickedImageTexture) {
                currentTexture = clickedImageTexture;
        }
        clickTimer.start(CLICK_DELAY_MS, [&]() {
                currentTexture = defaultImageTexture;
                if (onClickCallback) {
                        onClickCallback();
                }
        });
}

void Button::setOnClickCallback(std::function<void()> onClickCallback) {
        this->onClickCallback = onClickCallback;
}

SDL_Texture* Button::loadTexture(const char *path) const{
        const fs::path currentPath = fs::current_path();
        const fs::path imagePath = currentPath / path;

        SDL_Surface* surface = IMG_Load(imagePath.c_str());
        if (!surface) {
                throw std::runtime_error("Failed to load image: " + std::string(SDL_GetError()));
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(Window::getRenderer(), surface);
        SDL_DestroySurface(surface);
        if (!texture) {
                throw std::runtime_error("Failed to create texture: " + std::string(SDL_GetError()));
        }
        return texture;
}
