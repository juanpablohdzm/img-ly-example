//
// Created by Juan Pablo Hernandez Mosti on 25/04/25.
//

#include "TextureManager.h"

#include <SDL3/SDL_surface.h>
#include <filesystem>
#include <SDL3_image/SDL_image.h>
#include <ranges>


#include "Window.h"

namespace  fs = std::filesystem;

SDL_Texture* loadTexture(const char *path) {
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

SDL_Texture *TextureManager::getOrLoadTexture(const std::string &path) {
    auto* instance = getInstance();
    if (const auto it = instance->textures.find(path); it != instance->textures.end()) {
        return it->second;
    }

    SDL_Texture *texture = loadTexture(path.c_str());
    instance->textures.emplace(path, texture);
    return texture;
}

TextureManager::~TextureManager() {
    for (const auto texture : textures | std::views::values) {
        SDL_DestroyTexture(texture);
    }
}


