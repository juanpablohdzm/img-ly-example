//
// Created by Juan Pablo Hernandez Mosti on 14/04/25.
//

#include "Label.h"

#include <filesystem>
#include <iostream>
#include <SDL3_ttf/SDL_ttf.h>

#include "../Window.h"

namespace fs = std::filesystem;

Label::Label(
    const Position &position,
    int width,
    int height,
    const char* msg,
    const char *pathToFont,
    uint8_t fontSize,
    const Color& color) : Widget(position, width, height) {

    const fs::path currentPath = fs::current_path();
    const fs::path fontPath = currentPath / pathToFont;

    TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!font) {
        throw std::runtime_error("Failed to load font: " + std::string(SDL_GetError()));
    }

    SDL_Color textColor(color.r, color.g, color.b, color.a);

    SDL_Surface* textSurface = TTF_RenderText_Blended(font, msg, std::strlen(msg), textColor);
    TTF_CloseFont(font);

    if (!textSurface) {
        throw std::runtime_error("Failed to load renderTexture: " + std::string(SDL_GetError()));
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(Window::getRenderer(), textSurface);
    SDL_DestroySurface(textSurface);
    if (!textTexture) {
        throw std::runtime_error( "SDL_CreateTextureFromSurface Error: " + std::string(SDL_GetError()));
    }

    texture = textTexture;
}

Label::~Label() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Label::render() {
    const SDL_FRect fButtonRect = {
        static_cast<float>(rect.x),
        static_cast<float>(rect.y),
        static_cast<float>(getWidth()),
        static_cast<float>(getHeight())
    };
    SDL_RenderTexture(Window::getRenderer(), texture, nullptr, &fButtonRect);

}

void Label::onHoverEnter() {
}

void Label::onHoverExit() {
}
