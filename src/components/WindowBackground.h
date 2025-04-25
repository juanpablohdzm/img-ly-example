//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#ifndef WINDOWBACKGROUND_H
#define WINDOWBACKGROUND_H
#include <random>
#include <SDL3/SDL_stdinc.h>

#include "../utils/Singleton.h"

class Window;
class SDL_Renderer;
struct Position;
struct Velocity;

/**
 * @struct Star
 * @brief Represents a star particle in the background.
 *
 * The Star struct contains properties for rendering a star, including
 * its size and brightness.
 */
struct Star {
    float size;         ///< The drawn size of the star (in pixels).
    Uint8 brightness;   ///< Brightness for color intensity (0-255).
};

/**
 * @class WindowBackground
 * @brief A singleton class for managing and rendering the window background.
 *
 * The WindowBackground class is responsible for initializing, updating, and
 * rendering the background of the window. It uses particle effects to simulate
 * stars, with each star having a position, velocity, size, and brightness.
 */
class WindowBackground final : public Singleton<WindowBackground> {
    friend class Singleton<WindowBackground>; ///< Allows Singleton to access private members.

    /**
     * @brief Private constructor to enforce the singleton pattern.
     *
     * Initializes the random number generator used for star properties.
     */
    WindowBackground();

public:
    /**
     * @brief Initializes the background system.
     *
     * This function sets up the necessary components and entities for
     * rendering the background.
     */
    static void initialize();

    /**
     * @brief Updates the background state.
     *
     * This function updates the positions and properties of the stars
     * based on the elapsed time.
     *
     */
    static void update();

private:
    /**
     * @brief Draws a single star particle.
     *
     * This function renders a star at the specified position with the
     * given properties.
     *
     * @param renderer The SDL renderer used for drawing.
     * @param pos The position of the star.
     * @param star The properties of the star (size and brightness).
     */
    static void drawParticle(SDL_Renderer *renderer, const Position &pos, const Star &star);

    std::mt19937 gen; ///< Random number generator for star properties.
};

#endif //WINDOWBACKGROUND_H