//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//

#include "PlayerController.h"

#include <iostream>
#include <SDL3/SDL_events.h>
#include <ranges>


void PlayerController::run() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            for (const auto& func : quitEvent | std::views::values) {
                func();
            }
        }

        if (event.type & (SDL_EVENT_KEY_DOWN | SDL_EVENT_MOUSE_BUTTON_DOWN)) {
            executeKeyCommand(event);
        }
    }
}

Position PlayerController::getMousePosition() {
    Position mousePosition;
    SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
    return mousePosition;
}

void PlayerController::executeKeyCommand(const SDL_Event& event) {
    Uint32 key = 0;

    if (event.type == SDL_EVENT_KEY_DOWN) {
        key = event.key.key;
    } else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        key = event.button.button;
    }

    if (const auto it = keyEvents.find(key); it != keyEvents.end()) {
        for (const auto& func : it->second  | std::views::values) {
            func(event);
        }
    }
}
