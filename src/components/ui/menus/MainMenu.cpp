//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#include "MainMenu.h"

#include <glm/vec3.hpp>

#include "components/ECSComponents/Position.h"
#include "components/Window.h"
#include "components/ui/Sprite.h"
#include "components/ui/Button.h"

#include "components/GameManager.h"
#include "App.h"

MainMenu::MainMenu(PlayerController *playerController) : Canvas(playerController) {

    constexpr int bannerWidth = 978 * 0.5;
    constexpr int bannerHeight = 380 * 0.5;
    const float bannerPosX = (Window::getWidth() / 2.0f) - (bannerWidth / 2.0f);
    const float bannerPosY = (Window::getHeight() * 0.4) - (bannerHeight / 2.0f);
    const Position bannerPosition(glm::vec3( bannerPosX, bannerPosY, 0.0f));
    banner = std::make_unique<Sprite>(
        "resource/Main_Menu/Header.png",
        bannerPosition,
        bannerWidth,
        bannerHeight
    );

    constexpr float buttonWidth = 210 * 0.33f;
    constexpr float buttonHeight = 210 * 0.33f;

    const float playButtonPosX = Window::getWidth() * 0.33f - (buttonWidth / 2);
    const float playButtonPosY = Window::getHeight() * 0.7f - (buttonHeight / 2);
    const Position playButtonPostion(glm::vec3(playButtonPosX, playButtonPosY, 0.0f));
    playButton = std::make_unique<Button>(
        "resource/Buttons/BTNs/Play_BTN.png",
        "resource/Buttons/BTNs_Active/Play_BTN.png",
        "resource/Buttons/BTNs/Play_BTN.png",
        playButtonPostion,
        buttonWidth, buttonHeight
    );

    const float quitButtonPosX = Window::getWidth() * (2.0f / 3.0f) - (buttonWidth / 2.0f);
    const float quitButtonPosY = Window::getHeight() * 0.7f - (buttonHeight / 2.0f);
    const Position quitButtonPosition(glm::vec3(quitButtonPosX, quitButtonPosY, 0.0f));
    quitButton = std::make_unique<Button>(
        "resource/Buttons/BTNs/Close_BTN.png",
        "resource/Buttons/BTNs_Active/Close_BTN.png",
        "resource/Buttons/BTNs/Close_BTN.png",
        quitButtonPosition,
        buttonWidth, buttonHeight
    );

    addChild(banner.get());
    addChild(playButton.get());
    addChild(quitButton.get());

}

MainMenu::~MainMenu() {
}

void MainMenu::initialize() {
    Canvas::initialize();

    playButton->setOnClickCallback([]() {
            GameManager::setCurrentState(GameState::PLAYING);
        });

    quitButton->setOnClickCallback([]() {
            App::exit();
        });
}
