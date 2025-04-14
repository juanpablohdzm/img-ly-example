//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#include "Canvas.h"

#include <iostream>
#include <SDL3/SDL_mouse.h>

#include "Widget.h"
#include "../GameManager.h"
#include "../PlayerController.h"
#include "interfaces/Clickable.h"

Canvas::Canvas(PlayerController* playerController) : playerController(playerController) {

    if (!playerController) {
        throw std::runtime_error("PlayerController is null");
    }

    playerController->addKeyCallback(SDL_BUTTON_LEFT, this, &Canvas::onMouseClicked);
}

Canvas::~Canvas() {
    if (playerController) {
        playerController->clearKeyCallback(SDL_BUTTON_LEFT, this);
    }
}

void Canvas::update(float dt) {
    const auto [mouse_x, mouse_y] = PlayerController::getMousePosition();

    if (focusedWidget && !focusedWidget->isMouseOver(mouse_x, mouse_y)) {
        focusedWidget->onHoverExit();
        focusedWidget = nullptr;
    }

    for (auto& widget : widgets) {
        widget->render();
        if (widget->isMouseOver(mouse_x, mouse_y)) {
            widget->onHoverEnter();
            focusedWidget = widget;
        }
    }
}

void Canvas::addChild(Widget *widget) {
    widgets.insert(widget);
}

void Canvas::removeChild(Widget *widget) {
    widgets.erase(widget);
}

void Canvas::initialize() {
}

void Canvas::onMouseClicked(const SDL_Event& event) {

    if (!focusedWidget) {
        return;
    }

    // if we have a widget and the mouse is over it, we can click
    if (focusedWidget->isMouseOver(event.button.x, event.button.y)) {
        if (auto clickable = dynamic_cast<Clickable*>(focusedWidget)) {
            clickable->click();
        }
        return;
    } else {
        //...if we have a widget but the mouse is not over it, we need to clear the focused widget
        focusedWidget = nullptr;
    }

}
