//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#ifndef WIDGET_H
#define WIDGET_H
#include <SDL3/SDL_rect.h>

#include "../../utils/common.h"


class Widget {
public:
    Widget(const Position& position, float width, float height);
    virtual ~Widget() = default;

    virtual void render() = 0;
    virtual void onHoverEnter() = 0;
    virtual void onHoverExit() = 0;

    [[nodiscard]] SDL_FRect getRect() const { return rect; }
    [[nodiscard]] Position getPosition() const { return {rect.x * 1.0f, rect.y * 1.0f}; }
    [[nodiscard]] float getWidth() const { return rect.w; }
    [[nodiscard]] float getHeight() const { return rect.h; }
    [[nodiscard]] bool isMouseOver(int mouseX, int mouseY) const;


protected:
    SDL_FRect rect;
};



#endif //WIDGET_H
