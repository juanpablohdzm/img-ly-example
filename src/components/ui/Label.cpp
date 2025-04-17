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
    const char* msg,
    const Position& position,
    float width,
    float height,
    uint8_t fontSize,
    const Color& color,
    const char* pathToFont,
    bool setWidthAutomatically,
    bool setHeightAutomatically) :

    Widget(position, width, height),
    fontSize(fontSize),
    color(color),
    automaticWidth(setWidthAutomatically),
    automaticHeight(setHeightAutomatically) {

    if (!pathToFont) {
        pathToFont = "resource/fonts/Orbitron-Regular.ttf";
    }

    const fs::path currentPath = fs::current_path();
    const fs::path fontPath = currentPath / pathToFont;
    if (!fs::exists(fontPath)) {
        throw std::runtime_error("Font file does not exist: " + fontPath.string());
    }

    this->pathToFont = fontPath.string();
    font = loadFont(this->pathToFont.c_str());
    texture = loadTexture(font, msg);
}

Label::~Label() {
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
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

void Label::updateMessage(const char *msg) {
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    texture = loadTexture(font, msg);
}

TTF_Font* Label::loadFont(const char *fontPath) const {
    TTF_Font* font = TTF_OpenFont(fontPath, fontSize);
    if (!font) {
        throw std::runtime_error("Failed to load font: " + std::string(SDL_GetError()));
    }
    return font;
}

SDL_Texture * Label::loadTexture(TTF_Font* font, const char *msg){

    if ((automaticWidth || automaticHeight) && font) {
        int textWidth = 0;
        int textHeight = 0;
        if (TTF_GetStringSize(font, msg, std::strlen(msg), &textWidth, &textHeight)) {
            rect.w = automaticWidth ? textWidth : rect.w;
            rect.h = automaticHeight ? textHeight : rect.h;
        } else {
            std::cerr << "TTF_SizeText error: " << SDL_GetError() << std::endl;
        }
    }

    const SDL_Color textColor(color.r, color.g, color.b, color.a);

    SDL_Surface* textSurface = TTF_RenderText_Blended(font, msg, std::strlen(msg), textColor);

    if (!textSurface) {
        throw std::runtime_error("Failed to load renderTexture: " + std::string(SDL_GetError()));
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(Window::getRenderer(), textSurface);
    SDL_DestroySurface(textSurface);
    if (!textTexture) {
        throw std::runtime_error( "SDL_CreateTextureFromSurface Error: " + std::string(SDL_GetError()));
    }
    return textTexture;
}
