//
// Created by Juan Pablo Hernandez Mosti on 14/04/25.
//

#include "GameHud.h"

#include "../Label.h"
#include "../../PlayerController.h"
#include "../../Window.h"

GameHud::GameHud(PlayerController *playerController) : Canvas(playerController) {
    scoreLabel = std::make_unique<Label>(
        "Score:",
        Position(Window::getWidth() * 0.03, Window::getHeight() * 0.85f),
        Window::getWidth() * 0.25f,
        Window::getHeight() * 0.1f,
        52,
        Color(255, 255, 255, 255)
    );

    scoreValue = std::make_unique<Label>(
        "0",
        Position(Window::getWidth() * 0.3, Window::getHeight() * 0.85f),
        Window::getWidth() * 0.05f,
        Window::getHeight() * 0.1f,
        52,
        Color(255, 255, 255, 255),
        nullptr,
        true,
        true
        );


    addChild(scoreLabel.get());
    addChild(scoreValue.get());
}

GameHud::~GameHud() {
}

void GameHud::initialize() {
    Canvas::initialize();
}

void GameHud::update(float deltaTime) {
    Canvas::update(deltaTime);
}
