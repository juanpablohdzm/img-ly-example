//
// Created by Juan Pablo Hernandez Mosti on 28/04/25.
//

#include "GameOverMenu.h"
#include "components/ECSComponents/Position.h"
#include "components/ui/Sprite.h"
#include "components/Window.h"

GameOverMenu::GameOverMenu(PlayerController* playerController) : Canvas(playerController){
    constexpr int starWidth = 292 * 0.4;
    constexpr int starHeight = 280 * 0.4;
    const float starPosX = (Window::getWidth() / 2.0f) - (starWidth / 2.0f);
    const float starPosY = starHeight * 1.0f;
    const Position startPosition(glm::vec3( starPosX, starPosY, 0.0f));
    starSprite = std::make_unique<Sprite>(
        "resource/You_Win/Star_03.png",
        startPosition,
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

    addChild(banner.get());
    addChild(bannerBackground.get());
    addChild(starSprite.get());
}

GameOverMenu::~GameOverMenu(){

}