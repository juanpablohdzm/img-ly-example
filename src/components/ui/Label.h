//
// Created by Juan Pablo Hernandez Mosti on 14/04/25.
//

#ifndef LABEL_H
#define LABEL_H

#include <string>
#include "Widget.h"
#include "../../utils/Color.h"

class SDL_Texture;
class TTF_Font;

/**
 * @class Label
 * @brief A UI widget for displaying text.
 *
 * The Label class extends the Widget class and provides functionality
 * for rendering text with customizable font, size, color, and position.
 * It supports dynamic updates to the displayed message.
 */
class Label : public Widget {
public:
    /**
     * @brief Constructs a Label with the specified properties.
     *
     * @param msg The initial text message to display.
     * @param position The position of the label.
     * @param width The width of the label.
     * @param height The height of the label.
     * @param fontSize The font size of the text (default is 24).
     * @param color The color of the text (default is white).
     * @param pathToFont The file path to the font (optional).
     * @param setWidthAutomatically Whether to automatically set the width based on the text (default is false).
     * @param setHeightAutomatically Whether to automatically set the height based on the text (default is false).
     */
    Label(
        const char* msg,
        const Position& position,
        float width,
        float height,
        uint8_t fontSize = 24,
        const Color& color = Color(255, 255, 255, 255),
        const char* pathToFont = nullptr,
        bool setWidthAutomatically = false,
        bool setHeightAutomatically = false);

    /**
     * @brief Destructor for the Label class.
     *
     * Cleans up resources used by the label, including the font and texture.
     */
    ~Label() override;

    /**
     * @brief Renders the label.
     *
     * This function draws the text at its current position and size.
     */
    void render() override;

    /**
     * @brief Called when the mouse enters the label's area.
     *
     * This function can be overridden in derived classes to define custom behavior.
     */
    void onHoverEnter() override;

    /**
     * @brief Called when the mouse exits the label's area.
     *
     * This function can be overridden in derived classes to define custom behavior.
     */
    void onHoverExit() override;

    /**
     * @brief Updates the text message displayed by the label.
     *
     * @param msg The new text message to display.
     */
    void updateMessage(const char* msg);

private:
    /**
     * @brief Loads a font from the specified file path.
     *
     * @param fontPath The file path to the font.
     * @return A pointer to the loaded TTF_Font.
     */
    TTF_Font *loadFont(const char *fontPath) const;

    /**
     * @brief Creates a texture from the specified font and message.
     *
     * @param font The font to use for rendering the text.
     * @param msg The text message to render.
     * @return A pointer to the created SDL_Texture.
     */
    SDL_Texture* loadTexture(TTF_Font *font, const char *msg);

    TTF_Font* font; ///< The font used for rendering the text.
    SDL_Texture* texture; ///< The texture representing the rendered text.
    std::string pathToFont; ///< The file path to the font.
    uint8_t fontSize; ///< The font size of the text.
    Color color; ///< The color of the text.

    bool automaticWidth; ///< Whether the width is set automatically based on the text.
    bool automaticHeight; ///< Whether the height is set automatically based on the text.
};

#endif //LABEL_H