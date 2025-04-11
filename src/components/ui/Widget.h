//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#ifndef WIDGET_H
#define WIDGET_H
#include <SDL3/SDL_rect.h>


class Widget {
public:
    Widget(int x, int y, int width, int height);
    virtual ~Widget() = default;

    virtual void render() = 0;
    virtual void onHoverEnter() = 0;
    virtual void onHoverExit() = 0;

    [[nodiscard]] SDL_Rect getRect() const { return rect; }
    [[nodiscard]] int getX() const { return rect.x; }
    [[nodiscard]] int getY() const { return rect.y; }
    [[nodiscard]] int getWidth() const { return rect.w; }
    [[nodiscard]] int getHeight() const { return rect.h; }
    [[nodiscard]] bool isMouseOver(int mouseX, int mouseY) const;


protected:
    SDL_Rect rect;
};



#endif //WIDGET_H
