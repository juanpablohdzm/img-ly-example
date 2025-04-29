//
// Created by Juan Pablo Hernandez Mosti on 28/04/25.
//

#include "GameOverMenu.h"

#include "App.h"
#include "components/ECSComponents/Position.h"
#include "components/ui/Sprite.h"
#include "components/Window.h"
#include "components/ui/Button.h"

GameOverMenu::GameOverMenu(PlayerController* playerController) : Canvas(playerController){
    constexpr int starWidth = 292 * 0.4;
    constexpr int starHeight = 280 * 0.4;

    const float spacing = 10.0f;
    const float starPosX = (Window::getWidth() / 2.0f) - (starWidth / 2.0f);
    const float starPosY = starHeight * 1.0f;

    const float centerStarPosY = starPosY - 20.0f; // center star slightly more up
    const Position leftStarPosition(glm::vec3(starPosX - starWidth - spacing, starPosY, 0.0f));
    const Position centerStarPosition(glm::vec3(starPosX, centerStarPosY, 0.0f));
    const Position rightStarPosition(glm::vec3(starPosX + starWidth + spacing, starPosY, 0.0f));

    starSprites[0] = std::make_unique<Sprite>(
        "resource/You_Win/Star_03.png",
        leftStarPosition,
        starWidth,
        starHeight
    );
    starSprites[1] = std::make_unique<Sprite>(
        "resource/You_Win/Star_03.png",
        centerStarPosition,
        starWidth,
        starHeight
    );
    starSprites[2] = std::make_unique<Sprite>(
        "resource/You_Win/Star_03.png",
        rightStarPosition,
        starWidth,
        starHeight
    );




    constexpr int tableWidth = 361 * 1.4f;
    constexpr int tableHeight = 101 * 1.2f;
    const float tablePosX = (Window::getWidth() / 2.0f) - (tableWidth / 2.0f);
    const float tablePosY = (Window::getHeight() * 0.5f) - (tableHeight / 2.0f);
    const Position tablePosition(glm::vec3( tablePosX, tablePosY, 0.0f));
    bannerBackground = std::make_unique<Sprite>(
        "resource/You_Win/Table.png",
        tablePosition,
        tableWidth,
        tableHeight
    );

    constexpr int bannerWidth = 399 * 0.8f;
    constexpr int bannerHeight = 59 * 0.75f;
    const float bannerPosX = (Window::getWidth() / 2.0f) - (bannerWidth / 2.0f);
    const float bannerPosY = (Window::getHeight() * 0.49f) - (bannerHeight / 2.0f);
    const Position bannerPosition(glm::vec3( bannerPosX, bannerPosY, 0.0f));
    banner = std::make_unique<Sprite>(
        "resource/You_Win/Header.png",
        bannerPosition,
        bannerWidth,
        bannerHeight
    );

    constexpr float buttonWidth = 210 * 0.33f;
    constexpr float buttonHeight = 210 * 0.33f;

    const float quitButtonPosX = Window::getWidth() * 0.5f - (buttonWidth / 2.0f);
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
    addChild(bannerBackground.get());
    for (auto& starSprite : starSprites) {
        addChild(starSprite.get());
    }
    addChild(quitButton.get());
}

GameOverMenu::~GameOverMenu(){

}

void GameOverMenu::initialize() {
    Canvas::initialize();

    quitButton->setOnClickCallback([]() {
            App::exit();
        });
}