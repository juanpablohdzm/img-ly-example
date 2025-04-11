//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#include "Canvas.h"

#include "../PlayerController.h"

Canvas::Canvas(Window *window, PlayerController* playerController) : window(window), playerController(playerController) {
    if (!window) {
        throw std::runtime_error("Window is null");
    }
}

void Canvas::update(float dt) {
    for (auto& widget : widgets) {

    }
}
