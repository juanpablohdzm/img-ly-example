//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#ifndef MAINMENU_H
#define MAINMENU_H
#include <memory>

#include "../Canvas.h"

class Button;
class Sprite;
class GameManager;

/**
 * @class MainMenu
 * @brief A UI canvas representing the main menu of the game.
 *
 * The MainMenu class extends the Canvas class and provides functionality
 * for initializing and managing the main menu's UI components, such as
 * buttons and a banner.
 */
class MainMenu : public Canvas {
public:
    /**
     * @brief Constructs a MainMenu with a reference to a PlayerController.
     *
     * @param playerController A pointer to the PlayerController for handling input events.
     */
    MainMenu(PlayerController* playerController);

    /**
     * @brief Destructor for the MainMenu class.
     *
     * Ensures proper cleanup of the main menu's resources.
     */
    ~MainMenu() override;

    /**
     * @brief Initializes the main menu.
     *
     * This function sets up the main menu's UI components, such as the play and quit buttons,
     * and the banner.
     */
    void initialize() override;

private:
    std::unique_ptr<Button> playButton = nullptr; ///< A button to start the game.
    std::unique_ptr<Button> quitButton = nullptr; ///< A button to quit the game.
    std::unique_ptr<Sprite> banner = nullptr; ///< A banner image displayed in the main menu.
};

#endif //MAINMENU_H