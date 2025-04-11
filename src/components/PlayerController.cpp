//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//

#include "PlayerController.h"

#include <SDL3/SDL_events.h>
#include <ranges>


void PlayerController::run() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        // In SDL3 the quit event is typically SDL_EVENT_QUIT
        if (event.type == SDL_EVENT_QUIT) {
            for (const auto& func : quitEvent | std::views::values) {
                func();
            }
        }

        if (event.type == SDL_EVENT_KEY_DOWN) {
            executeKeyCommand(event.key.key);
        }
    }
}

void PlayerController::executeKeyCommand(Uint32 key) {
    if (const auto it = keyEvents.find(key); it != keyEvents.end()) {
        for (const auto& func : it->second  | std::views::values) {
            func();
        }
    }
}
