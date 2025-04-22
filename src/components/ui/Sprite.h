//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#ifndef SPRITE_H
#define SPRITE_H
#include <SDL3/SDL_render.h>

#include "Widget.h"

/**
 * @class Sprite
 * @brief A UI widget that represents a drawable image.
 *
 * The Sprite class extends the Widget class and provides functionality
 * for rendering an image at a specified position and size. It also
 * supports updating its position dynamically.
 */
class Sprite : public Widget {
public:
    /**
     * @brief Constructs a Sprite with the specified image, position, width, and height.
     *
     * @param imagePath The file path to the image to be rendered.
     * @param position The initial position of the sprite.
     * @param width The width of the sprite.
     * @param height The height of the sprite.
     * @param angle The rotation angle of the sprite (default is 0.0f).
     */
    Sprite(
        const char* imagePath,
        const Position& position,
        float width, float height,
        float angle = 0.0f);

    /**
     * @brief Destructor for the Sprite class.
     *
     * Cleans up the resources used by the sprite, including the loaded texture.
     */
    ~Sprite() override;

    /**
     * @brief Renders the sprite.
     *
     * This function draws the sprite's image at its current position and size.
     */
    void render() override;

    /**
     * @brief Called when the mouse enters the sprite's area.
     *
     * This function is currently a no-op and can be overridden in derived classes.
     */
    void onHoverEnter() override {};

    /**
     * @brief Called when the mouse exits the sprite's area.
     *
     * This function is currently a no-op and can be overridden in derived classes.
     */
    void onHoverExit() override {};

    /**
     * @brief Updates the position of the sprite.
     *
     * @param position The new position of the sprite.
     */
    void updatePosition(const Position& position);

    /**
     * @brief Sets the rotation angle of the sprite.
     *
     * @param angle The new rotation angle in degrees.
     */
    void setAngleRotation(float angle) {
        currentAngle = angle;
    }

    /**
     * @brief Gets the current rotation angle of the sprite.
     *
     * @return The current rotation angle in degrees.
     */
    [[nodiscard]] float getCurrentAngleRotation () const {
        return currentAngle;
    }

private:
    /**
     * @brief Loads a texture from the specified file path.
     *
     * @param path The file path to the image.
     * @return A pointer to the loaded SDL_Texture.
     */
    SDL_Texture* loadTexture(const char* path) const;

    float currentAngle; ///< The current rotation angle of the sprite.
    SDL_Texture* defaultImageTexture; ///< The texture representing the sprite's image.
};

#endif //SPRITE_H