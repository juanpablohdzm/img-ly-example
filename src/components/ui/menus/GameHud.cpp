//
// Created by Juan Pablo Hernandez Mosti on 14/04/25.
//

#include "GameHud.h"

#include "components/ECSComponents/Position.h"
#include "components/ui/Label.h"
#include "components/ECSManager.h"
#include "components/Window.h"

GameHud::GameHud(PlayerController *playerController) : Canvas(playerController) {
    scoreLabel = std::make_unique<Label>(
        "Score:",
        Position(glm::vec3(Window::getWidth() * 0.03, Window::getHeight() * 0.9f, 0.0f)),
        Window::getWidth() * 0.25f,
        Window::getHeight() * 0.1f,
        36,
        Color(255, 255, 255, 255),
        nullptr,
        true,
        true
    );

    scoreValue = std::make_unique<Label>(
        "0",
        Position(glm::vec3(Window::getWidth() * 0.20, Window::getHeight() * 0.9f, 0.0f)),
        Window::getWidth() * 0.05f,
        Window::getHeight() * 0.1f,
        36,
        Color(255, 255, 255, 255),
        nullptr,
        true,
        true
        );

    waveLabel = std::make_unique<Label>(
        "Wave:",
        Position(glm::vec3(Window::getWidth() * 0.5f - 125.0f, 25.0f, 0.0f)),
        Window::getWidth() * 0.25f,
        Window::getHeight() * 0.1f,
        52,
        Color(255, 255, 255, 255),
        nullptr,
        true,
        true
    );

    waveValue = std::make_unique<Label>(
        "0",
        Position(glm::vec3(Window::getWidth() * 0.5f + 95.0f, 25.0f, 0.0f)),
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
    addChild(waveLabel.get());
    addChild(waveValue.get());
}

GameHud::~GameHud() {
}

void GameHud::initialize() {
    Canvas::initialize();
}

void GameHud::update() {
    Canvas::update();
}

void GameHud::updateScore(int score) const {
    scoreValue->updateMessage(std::to_string(score).c_str());
}
