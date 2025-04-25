//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#ifndef BUTTON_H
#define BUTTON_H

#include "interfaces/Clickable.h"
#include "Widget.h"
#include "../../utils/Timer.h"

class SDL_Renderer;
class SDL_Texture;

/**
 * @class Button
 * @brief A UI widget that represents an interactive button.
 *
 * The Button class extends the Widget and Clickable interfaces, providing
 * functionality for rendering a button with different states (default, hover, clicked),
 * handling hover and click events, and executing a callback when clicked.
 */
class Button : public Widget, public Clickable {
public:
    /**
     * @brief Constructs a Button with the specified properties.
     *
     * @param defaultImagePath The file path to the default button image.
     * @param hoverImagePath The file path to the hover button image.
     * @param clickedImagePath The file path to the clicked button image.
     * @param position The position of the button.
     * @param width The width of the button.
     * @param height The height of the button.
     */
    Button(
        const char* defaultImagePath,
        const char* hoverImagePath,
        const char* clickedImagePath,
        const Position& position,
        float width, float height);

    /**
     * @brief Renders the button.
     *
     * This function draws the button's current texture based on its state.
     */
    void render() override;

    /**
     * @brief Called when the mouse enters the button's area.
     *
     * Updates the button's texture to the hover state.
     */
    void onHoverEnter() override;

    /**
     * @brief Called when the mouse exits the button's area.
     *
     * Updates the button's texture to the default state.
     */
    void onHoverExit() override;

    /**
     * @brief Called when the button is clicked.
     *
     * Updates the button's texture to the clicked state and triggers the onClick callback.
     */
    void click() override;

    /**
     * @brief Sets the callback function to be executed when the button is clicked.
     *
     * @param onClickCallback A function to be called when the button is clicked.
     */
    virtual void setOnClickCallback(std::function<void()>&& onClickCallback);

private:
    SDL_Texture* currentTexture; ///< The texture currently being rendered.

    SDL_Texture* defaultImageTexture; ///< The texture for the default button state.
    SDL_Texture* hoverImageTexture; ///< The texture for the hover button state.
    SDL_Texture* clickedImageTexture; ///< The texture for the clicked button state.

    Timer clickTimer; ///< A timer to manage the button's click state duration.
    std::function<void()> onClickCallback; ///< The callback function executed on button click.
};

#endif //BUTTON_H