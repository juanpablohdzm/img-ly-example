//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#include "WindowBackground.h"

#include <random>
#include <SDL3/SDL_render.h>
#include <__random/random_device.h>
#include "../utils/common.h"
#include "Window.h"

WindowBackground::WindowBackground(entt::registry* registry, Window* window)
    : window(window), registry(registry), gen(std::random_device{}()) {

    if (!window) {
        throw std::runtime_error("Window is null");
    }
    if (!registry) {
        throw std::runtime_error("Registry is null");
    }

    std::uniform_int_distribution disWidth(0, window->getWidth());
    std::uniform_int_distribution disHeight(0, window->getHeight());
    std::uniform_real_distribution disSpeed(2.0f, 6.0f);
    std::uniform_real_distribution disSize(1.5f, 3.5f);
    std::uniform_int_distribution disBrightness(150, 255);

    constexpr uint32_t starCount = 500;
    for (uint32_t i = 0; i < starCount; ++i) {
        const auto entity = registry->create();

        float speed = disSpeed(gen);
        registry->emplace<Velocity>(entity, 0.0f, speed);

        registry->emplace<Position>(entity,
                                    static_cast<float>(disWidth(gen)),
                                    static_cast<float>(disHeight(gen)));

        registry->emplace<Star>(entity, disSize(gen), static_cast<Uint8>(disBrightness(gen)));
    }
}

void WindowBackground::update(float dt) {
    auto view = registry->view<Position, Velocity, Star>();
    for (auto [entity, pos, vel, star] : view.each()) {

        pos.y += vel.dy * dt;

        if (pos.y > window->getHeight()) {
            pos.y = -star.size;
            std::uniform_int_distribution disWidth(0, window->getWidth());
            pos.x = static_cast<float>(disWidth(gen));
        }

        auto* renderer = window->getRenderer();
        drawParticle(renderer, pos, star);
    }
}

void WindowBackground::drawParticle(SDL_Renderer* renderer, const Position& pos, const Star& star) {
    SDL_SetRenderDrawColor(renderer, star.brightness, star.brightness, star.brightness, 255);
    const SDL_FRect rect { pos.x, pos.y, star.size, star.size };
    SDL_RenderFillRect(renderer, &rect);
}
