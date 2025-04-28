//
// Created by Juan Pablo Hernandez Mosti on 14/04/25.
//

#pragma once

#include "components/ui/Canvas.h"

class Label;
class Widget;

/**
 * @class GameHud
 * @brief Represents the in-game HUD (Heads-Up Display) for the player.
 *
 * The GameHud class is responsible for managing and displaying the player's HUD,
 * including elements such as the score label and score value. It inherits from
 * the Canvas class and overrides its initialization and update methods.
 */
class GameHud : public Canvas {

public:
    /**
     * @brief Constructs a GameHud object.
     * @param playerController A pointer to the PlayerController associated with this HUD.
     */
    GameHud(PlayerController* playerController);

    /**
     * @brief Destroys the GameHud object and releases resources.
     */
    ~GameHud() override;

    /**
     * @brief Initializes the HUD components.
     *
     * This method is called to set up the HUD elements, such as creating widgets
     * for displaying the score.
     */
    void initialize() override;

    /**
     * @brief Updates the HUD state.
     *
     * This method is called every frame to update the HUD elements, such as
     * refreshing the score display.
     */
    void update() override;

    /**
     * @brief Updates the score display with the given score.
     *
     * @param score The score amount to be displayed
     */
    void updateScore(int score) const;

private:
    /**
     * @brief A widget for displaying the score label (e.g., "Score:").
     */
    std::unique_ptr<Widget> scoreLabel;

    /**
     * @brief A widget for displaying the score value.
     */
    std::unique_ptr<Label> scoreValue;
};
