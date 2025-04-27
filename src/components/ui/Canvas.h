//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#pragma once

#include <unordered_set>
#include <SDL3/SDL_events.h>

class PlayerController;
class Widget;

/**
 * @class Canvas
 * @brief A container for managing and rendering UI widgets.
 *
 * The Canvas class provides functionality to manage a collection of widgets,
 * handle input events, and update the state of its child widgets. It also
 * integrates with the PlayerController for event handling.
 */
class Canvas {
public:
    /**
     * @brief Constructs a Canvas with a reference to a PlayerController.
     *
     * @param playerController A pointer to the PlayerController for handling input events.
     */
    explicit Canvas(PlayerController* playerController);

    /**
     * @brief Virtual destructor for the Canvas class.
     *
     * Ensures proper cleanup of derived classes.
     */
    virtual ~Canvas();

    /**
     * @brief Updates the state of the canvas and its child widgets.
     *
     * This function is called periodically to update the canvas and its widgets.
     *
     */
    virtual void update();

    /**
     * @brief Adds a widget to the canvas.
     *
     * @param widget A pointer to the widget to be added.
     */
    virtual void addChild(Widget* widget);

    /**
     * @brief Removes a widget from the canvas.
     *
     * @param widget A pointer to the widget to be removed.
     */
    virtual void removeChild(Widget* widget);

    /**
     * @brief Initializes the canvas.
     *
     * This function is called to set up the canvas before it is used.
     */
    virtual void initialize();

protected:
    /**
     * @brief Handles mouse click events.
     *
     * This function is called when a mouse click event occurs and processes
     * the event for the canvas and its widgets.
     *
     * @param event The SDL_Event containing the mouse click information.
     */
    void onMouseClicked(const SDL_Event& event);

    std::unordered_set<Widget*> widgets; ///< A collection of widgets managed by the canvas.
    PlayerController* playerController = nullptr; ///< A pointer to the PlayerController for event handling.
    Widget* focusedWidget = nullptr; ///< A pointer to the currently focused widget.
};
