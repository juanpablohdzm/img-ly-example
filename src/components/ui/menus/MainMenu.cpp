//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#include "MainMenu.h"

#include "../../../utils/common.h"
#include "../../Window.h"
#include "../Sprite.h"
#include "../Button.h"
#include <iostream>

#include "../../GameManager.h"
#include "../../../App.h"

MainMenu::MainMenu(PlayerController *playerController) : Canvas(playerController) {

    constexpr int bannerWidth = 978 * 0.5;
    constexpr int bannerHeight = 380 * 0.5;
    const float bannerPosX = (Window::getWidth() / 2.0f) - (bannerWidth / 2.0f);
    const float bannerPosY = (Window::getHeight() * 0.4) - (bannerHeight / 2.0f);
    const Position bannerPosition{ bannerPosX, bannerPosY };
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
    const Position playButtonPostion{ playButtonPosX, playButtonPosY };
    playButton = std::make_unique<Button>(
        "resource/Buttons/BTNs/Play_BTN.png",
        "resource/Buttons/BTNs_Active/Play_BTN.png",
        "resource/Buttons/BTNs/Play_BTN.png",
        playButtonPostion,
        buttonWidth, buttonHeight
    );

    const float quitButtonPosX = Window::getWidth() * (2.0f / 3.0f) - (buttonWidth / 2.0f);
    const float quitButtonPosY = Window::getHeight() * 0.7f - (buttonHeight / 2.0f);
    const Position quitButtonPosition{ quitButtonPosX, quitButtonPosY };
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
