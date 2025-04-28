//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#pragma once

#include <SDL3/SDL_video.h>

#include "utils/Color.h"
#include "utils/Singleton.h"

// Forward declarations for SDL classes
class SDL_Window;
class SDL_Renderer;

/**
 * @class Window
 * @brief A singleton class that manages an SDL window and renderer.
 *
 * The Window class provides functionality to initialize, clear, and present
 * an SDL window and renderer. It also allows access to the renderer, window
 * dimensions, and manages the background color.
 */
class Window final : public Singleton<Window> {
    friend class Singleton<Window>; // Allows Singleton to access private members of Window.

    /**
     * @brief Private constructor to enforce singleton pattern.
     */
    Window();

public:
    /**
     * @brief Initializes the SDL window and renderer.
     *
     * @param title The title of the window.
     * @param width The width of the window in pixels.
     * @param height The height of the window in pixels.
     * @param color The background color of the window (default is black).
     */
    static void initialize(const char* title, int width, int height, const Color& color = {0, 0, 0, 255});

    /**
     * @brief Clears the window with the specified background color.
     */
    static void clearWindow();

    /**
     * @brief Presents the current render to the window.
     */
    static void presentRender();

    /**
     * @brief Destructor to clean up SDL resources.
     */
    ~Window();

    /**
     * @brief Gets the window object of SDL.
     *
     * @return The SDL_Window pointer.
     */
    static SDL_Window * getWindow() {return getInstance()->window;}

    /**
     * @brief Gets the width of the window.
     *
     * @return The width of the window in pixels.
     */
    [[nodiscard]] static int getWidth() { return getInstance()->width; }

    /**
     * @brief Gets the height of the window.
     *
     * @return The height of the window in pixels.
     */
    [[nodiscard]] static int getHeight() { return getInstance()->height; }

    /**
     * @brief Gets the SDL renderer associated with the window.
     *
     * @return A pointer to the SDL_Renderer.
     */
    [[nodiscard]] static SDL_Renderer* getRenderer() { return getInstance()->renderer; }

private:
    Color color; ///< The background color of the window.
    SDL_Window* window = nullptr; ///< Pointer to the SDL_Window instance.
    SDL_Renderer* renderer = nullptr; ///< Pointer to the SDL_Renderer instance.

    int width, height; ///< Dimensions of the window in pixels.
};