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
        const char* imagePath,
        const Position& position,
        float width, float height);

    ~Sprite() override;

    void render() override;
    void onHoverEnter() override {};
    void onHoverExit() override {};
    void updatePosition(const Position& position);

private:
    SDL_Texture* loadTexture(const char* path) const;

    SDL_Texture* defaultImageTexture;
};



#endif //SPRITE_H
