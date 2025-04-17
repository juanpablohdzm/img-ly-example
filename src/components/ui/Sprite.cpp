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
        float width, float height)
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

        SDL_RenderTexture(Window::getRenderer(), defaultImageTexture, nullptr, &rect);
}

void Sprite::updatePosition(const Position &position) {
        rect.x = position.x;
        rect.y = position.y;
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
