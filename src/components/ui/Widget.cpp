//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#include "Widget.h"

#include <SDL3/SDL_rect.h>

Widget::Widget(int x, int y, int width, int height): rect(x, y, width, height) {
}

bool Widget::isMouseOver(int mouseX, int mouseY) const {
    const SDL_Point clickedPos{mouseX, mouseY};
    return SDL_PointInRect(&clickedPos, &rect);
}
