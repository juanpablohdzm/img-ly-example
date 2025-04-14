//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#ifndef WINDOWBACKGROUND_H
#define WINDOWBACKGROUND_H
#include <random>
#include <entt/entt.hpp>
#include <SDL3/SDL_stdinc.h>

class Window;
class SDL_Renderer;
struct Position;
struct Velocity;

struct Star {
    float size;         // The drawn size of the star (in pixels)
    Uint8 brightness;   // Brightness for color intensity (0-255)
};

class WindowBackground {
public:
    WindowBackground(entt::registry* registry, Window* window);

    void update(float dt);

private:

    static void drawParticle(SDL_Renderer *renderer, const Position &pos, const Star& star);

    Window* window;
    entt::registry* registry;
    std::mt19937 gen;
};



#endif //WINDOWBACKGROUND_H
