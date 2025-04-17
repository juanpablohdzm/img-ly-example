//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#include "Widget.h"

#include <SDL3/SDL_rect.h>

Widget::Widget(const Position& position, float width, float height): rect(position.x, position.y, width, height) {
}

bool Widget::isMouseOver(int mouseX, int mouseY) const {
    const SDL_Point clickedPos{mouseX, mouseY};
    const SDL_Rect irect {
    static_cast<int>(rect.x),
        static_cast<int>(rect.y),
        static_cast<int>(rect.w),
        static_cast<int>(rect.h)
    };
    return SDL_PointInRect(&clickedPos, &irect);
}
