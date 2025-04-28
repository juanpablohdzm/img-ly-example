//
// Created by Juan Pablo Hernandez Mosti on 28/04/25.
//

#include "GameOverMenu.h"
#include "components/ECSComponents/Position.h"
#include "components/ui/Sprite.h"
#include "components/Window.h"

GameOverMenu::GameOverMenu(PlayerController* playerController) : Canvas(playerController){
  constexpr int bannerWidth = 978 * 0.5;
    constexpr int bannerHeight = 380 * 0.5;
    const float bannerPosX = (Window::getWidth() / 2.0f) - (bannerWidth / 2.0f);
    const float bannerPosY = (Window::getHeight() * 0.4) - (bannerHeight / 2.0f);
    const Position bannerPosition(glm::vec3( bannerPosX, bannerPosY, 0.0f));
    banner = std::make_unique<Sprite>(
        "resource/You_Win/Header.png",
        bannerPosition,
        bannerWidth,
        bannerHeight
    );

    addChild(banner.get());
}

GameOverMenu::~GameOverMenu(){

}