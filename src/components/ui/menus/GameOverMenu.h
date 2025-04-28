//
// Created by Juan Pablo Hernandez Mosti on 28/04/25.
//

#pragma once

#include "components/ui/Canvas.h"
#include <memory>

class Sprite;
class PlayerController;

/**
 * @brief Represents the Game Over menu interface.
 */
class GameOverMenu : public Canvas {
public:
    /**
     * @brief Constructs a new GameOverMenu object.
     * @param playerController A pointer to the player controller.
     */
    GameOverMenu(PlayerController* playerController);

    /**
     * @brief Destructs the GameOverMenu object.
     */
    ~GameOverMenu() override;
private:
    /**
     * @brief The banner sprite displayed in the game over menu.
     */
    std::unique_ptr<Sprite> banner = nullptr;
};
