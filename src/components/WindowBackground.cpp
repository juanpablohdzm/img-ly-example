//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#include "WindowBackground.h"

#include <random>
#include <SDL3/SDL_render.h>
#include <__random/random_device.h>

#include "ECSManager.h"
#include "Window.h"
#include "ECSComponents/Position.h"
#include "ECSComponents/Speed.h"
#include "ECSComponents/Velocity.h"

WindowBackground::WindowBackground() :  gen(std::random_device{}()){
}

void WindowBackground::initialize() {

    auto* instance = getInstance();

    std::uniform_int_distribution disWidth(0, Window::getWidth());
    std::uniform_int_distribution disHeight(0, Window::getHeight());
    std::uniform_real_distribution disSpeed(2.0f, 6.0f);
    std::uniform_real_distribution disSize(1.5f, 3.5f);
    std::uniform_int_distribution disBrightness(150, 255);

    constexpr uint32_t starCount = 500;
    for (uint32_t i = 0; i < starCount; ++i) {
        const auto entity = ECSManager::create();

        float speed = disSpeed(instance->gen);
        ECSManager::emplace<Velocity>(entity, Velocity(glm::vec3(0.0f, 0.1f, 0.0f)));
        ECSManager::emplace<Speed>(entity, speed);

        ECSManager::emplace<Position>(entity, Position(glm::vec3(static_cast<float>(disWidth(instance->gen)), static_cast<float>(disHeight(instance->gen)), 0.0f)));

        ECSManager::emplace<Star>(entity, disSize(instance->gen), static_cast<Uint8>(disBrightness(instance->gen)));
    }
}

void WindowBackground::update() {
    auto* instance = getInstance();
    for (auto [entity, pos, star] : ECSManager::view<Position, Star>().each()) {

        if (pos.value.y > Window::getHeight()) {
            pos.value.y = -star.size;
            std::uniform_int_distribution disWidth(0, Window::getWidth());
            pos.value.x = static_cast<float>(disWidth(instance->gen));
        }

        auto* renderer = Window::getRenderer();
        drawParticle(renderer, pos, star);
    }
}

void WindowBackground::drawParticle(SDL_Renderer* renderer, const Position& pos, const Star& star) {
    SDL_SetRenderDrawColor(renderer, star.brightness, star.brightness, star.brightness, 255);
    const SDL_FRect rect { pos.value.x, pos.value.y, star.size, star.size };
    SDL_RenderFillRect(renderer, &rect);
}
