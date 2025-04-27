//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#include "Sprite.h"

#include <stdexcept>
#include <SDL3_image/SDL_image.h>

#include "components/ECSComponents/Position.h"
#include "components/TextureManager.h"
#include "components/Window.h"


Sprite::Sprite(
        const char *imagePath,
        const Position& position,
        float width, float height,
        float angle)
        : Widget(position, width, height), currentAngle(angle){

        if (!imagePath) {
                throw std::invalid_argument("Default image path is null");
        }

        defaultImageTexture = TextureManager::getOrLoadTexture(imagePath);
}

void Sprite::render(){
        SDL_RenderTextureRotated(Window::getRenderer(), defaultImageTexture, nullptr, &rect, currentAngle, nullptr, SDL_FLIP_NONE);
}

void Sprite::updatePosition(const Position &position) {
        rect.x = position.value.x;
        rect.y = position.value.y;
}
