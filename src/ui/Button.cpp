//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#include "Button.h"

#include <stdexcept>
#include <string>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>

Button::Button(SDL_Renderer *renderer, const char *imagePath, int x, int y, int width, int height) :
renderer(renderer), buttonRect{x, y, width, height} {
        SDL_Surface* surface = IMG_Load(imagePath);
        if (!surface) {
                throw std::runtime_error("Failed to load image: " + std::string(SDL_GetError()));
        }
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_DestroySurface(surface);
        if (!texture) {
                throw std::runtime_error("Failed to create texture: " + std::string(SDL_GetError()));
        }
}

Button::~Button(){
        if (texture) {
                SDL_DestroyTexture(texture);
        }
}

void Button::render() const {
        const SDL_FRect fButtonRect = {
                static_cast<float>(buttonRect.x),
                static_cast<float>(buttonRect.y),
                static_cast<float>(buttonRect.w),
                static_cast<float>(buttonRect.h)
        };
        SDL_RenderTexture(renderer, texture, nullptr, &fButtonRect);
}

bool Button::isClicked(int mouseX, int mouseY) const {
        const SDL_Point clickedPos{mouseX, mouseY};
        return SDL_PointInRect(&clickedPos, &buttonRect);
}
