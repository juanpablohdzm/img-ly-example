//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#pragma once

#include <SDL3/SDL_rect.h>

struct Position;

/**
 * @class Widget
 * @brief An abstract base class for UI widgets.
 *
 * The Widget class provides a foundation for creating UI components.
 * It defines common properties such as position, width, and height,
 * and enforces the implementation of rendering and hover behavior.
 */
class Widget {
public:
    /**
     * @brief Constructs a Widget with the specified position, width, and height.
     *
     * @param position The position of the widget.
     * @param width The width of the widget.
     * @param height The height of the widget.
     */
    Widget(const Position& position, float width, float height);

    /**
     * @brief Virtual destructor for the Widget class.
     *
     * Ensures proper cleanup of derived classes.
     */
    virtual ~Widget() = default;

    /**
     * @brief Renders the widget.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     */
    virtual void render() = 0;

    /**
     * @brief Called when the mouse enters the widget's area.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     */
    virtual void onHoverEnter() = 0;

    /**
     * @brief Called when the mouse exits the widget's area.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     */
    virtual void onHoverExit() = 0;

    /**
     * @brief Gets the rectangle representing the widget's bounds.
     *
     * @return An SDL_FRect representing the widget's bounds.
     */
    [[nodiscard]] SDL_FRect getRect() const { return rect; }

    /**
     * @brief Gets the position of the widget.
     *
     * @return A Position object representing the widget's position.
     */
    [[nodiscard]] Position getPosition() const;

    /**
     * @brief Gets the width of the widget.
     *
     * @return The width of the widget.
     */
    [[nodiscard]] float getWidth() const { return rect.w; }

    /**
     * @brief Gets the height of the widget.
     *
     * @return The height of the widget.
     */
    [[nodiscard]] float getHeight() const { return rect.h; }

    /**
     * @brief Checks if the mouse is over the widget.
     *
     * @param mouseX The x-coordinate of the mouse.
     * @param mouseY The y-coordinate of the mouse.
     * @return True if the mouse is over the widget, false otherwise.
     */
    [[nodiscard]] bool isMouseOver(int mouseX, int mouseY) const;

protected:
    SDL_FRect rect; ///< The rectangle representing the widget's bounds.
};
