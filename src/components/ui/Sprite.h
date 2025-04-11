//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#ifndef SPRITE_H
#define SPRITE_H
#include <SDL3/SDL_render.h>

#include "Widget.h"


class Sprite : public Widget {
public:
    Sprite(
        SDL_Renderer* renderer,
        const char* imagePath,
        const Position& position,
        int width, int height);

    ~Sprite() override;

    void render() override;
    void onHoverEnter() override {};
    void onHoverExit() override {};

private:
    SDL_Texture* loadTexture(const char* path) const;

    SDL_Renderer* renderer;

    SDL_Texture* defaultImageTexture;
};



#endif //SPRITE_H
