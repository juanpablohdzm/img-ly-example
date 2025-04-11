//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#include "MainMenu.h"

#include "../../../utils/common.h"
#include "../../Window.h"
#include "../Sprite.h"
#include "../Button.h"
#include <iostream>

MainMenu::MainMenu(Window *window, PlayerController *playerController) : Canvas(window, playerController) {

    constexpr int bannerWidth = 978 * 0.5;
    constexpr int bannerHeight = 380 * 0.5;
    const float bannerPosX = (window->getWidth() / 2.0f) - (bannerWidth / 2.0f);
    const float bannerPosY = (window->getHeight() * 0.4) - (bannerHeight / 2.0f);
    const Position bannerPosition{ bannerPosX, bannerPosY };
    banner = std::make_unique<Sprite>(
        window->getRenderer(),
        "resource/Main_Menu/Header.png",
        bannerPosition,
        bannerWidth,
        bannerHeight
    );

    constexpr float buttonWidth = 410 * 0.33f;
    constexpr float buttonHeight = 121 * 0.33f;

    const float playButtonPosX = window->getWidth() * 0.33f - (buttonWidth / 2);
    const float playButtonPosY = window->getHeight() * 0.7f - (buttonHeight / 2);
    const Position playButtonPostion{ playButtonPosX, playButtonPosY };
    playButton = std::make_unique<Button>(
        window->getRenderer(),
        "resource/Main_Menu/Start_BTN.png",
        nullptr,
        nullptr,
        playButtonPostion,
        buttonWidth, buttonHeight,
        [this]() {
            std::cout << "Play button clicked" << std::endl;
        }
    );

    const float quitButtonPosX = window->getWidth() * (2.0f / 3.0f) - (buttonWidth / 2.0f);
    const float quitButtonPosY = window->getHeight() * 0.7f - (buttonHeight / 2.0f);
    const Position quitButtonPosition{ quitButtonPosX, quitButtonPosY };
    quitButton = std::make_unique<Button>(
        window->getRenderer(),
        "resource/Main_Menu/Exit_BTN.png",
        nullptr,
        nullptr,
        quitButtonPosition,
        buttonWidth, buttonHeight,
        [this]() {
            std::cout << "Quit button clicked" << std::endl;
        }
    );

    addChild(banner.get());
    addChild(playButton.get());
    addChild(quitButton.get());
}

MainMenu::~MainMenu() {
}
