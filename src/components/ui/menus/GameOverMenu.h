//
// Created by Juan Pablo Hernandez Mosti on 28/04/25.
//

#pragma once

#include "components/ui/Canvas.h"
#include <memory>

class Button;
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

    /**
     * @brief Initializes the GameOverMenu.
     *
     * This function sets up the GameOverMenu's UI components.
     */
    void initialize() override;
private:

    std::unique_ptr<Sprite> bannerBackground = nullptr; ///< The background image for the Game Over menu.
    std::unique_ptr<Sprite> banner = nullptr; ///< The banner image displayed in the Game Over menu.
    std::array<std::unique_ptr<Sprite>, 3> starSprites; ///< The star sprite displayed in the Game Over menu.
    std::unique_ptr<Button> quitButton = nullptr; ///< A button to quit the game.
};
