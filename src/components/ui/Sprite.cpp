//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#include "Sprite.h"

#include <stdexcept>
#include <filesystem>
#include <SDL3_image/SDL_image.h>

#include "../Window.h"


namespace  fs = std::filesystem;
Sprite::Sprite(
        const char *imagePath,
        const Position& position,
        int width, int height)
        : Widget(position, width, height){

        if (!imagePath) {
                throw std::invalid_argument("Default image path is null");
        }

        defaultImageTexture = loadTexture(imagePath);
}

Sprite::~Sprite(){

        if (defaultImageTexture) {
                SDL_DestroyTexture(defaultImageTexture);
        }
}

void Sprite::render(){

        const SDL_FRect fButtonRect = {
                static_cast<float>(rect.x),
                static_cast<float>(rect.y),
                static_cast<float>(getWidth()),
                static_cast<float>(getHeight())
        };
        SDL_RenderTexture(Window::getRenderer(), defaultImageTexture, nullptr, &fButtonRect);
}

SDL_Texture* Sprite::loadTexture(const char *path) const {
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
