//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#include "Button.h"

#include <stdexcept>
#include <SDL3/SDL_render.h>
#include <__filesystem/operations.h>

#include "../TextureManager.h"
#include "../Window.h"


#define CLICK_DELAY_MS 200

Button::Button(
        const char *defaultImagePath,
        const char *hoverImagePath,
        const char *clickedImagePath,
        const Position& position,
        float width, float height)
        : Widget(position, width, height){

        if (!defaultImagePath) {
                throw std::invalid_argument("Default image path is null");
        }

        defaultImageTexture = TextureManager::getOrLoadTexture(defaultImagePath);

        if (hoverImagePath) {
            hoverImageTexture = TextureManager::getOrLoadTexture(hoverImagePath);
        }
        if (clickedImagePath) {
            clickedImageTexture = TextureManager::getOrLoadTexture(clickedImagePath);
        }

        currentTexture = defaultImageTexture;
}

void Button::render(){
        SDL_RenderTexture(Window::getRenderer(), currentTexture, nullptr, &rect);
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

void Button::setOnClickCallback(std::function<void()>&& onClickCallback) {
        this->onClickCallback = std::move(onClickCallback);
}
