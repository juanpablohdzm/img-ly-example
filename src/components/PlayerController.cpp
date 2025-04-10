//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//

#include "PlayerController.h"

#include <SDL3/SDL_events.h>
#include <ranges>

#include "commands/Command.h"

void PlayerController::addKeyCommand(const Uint32 key, const Command* command) {

    auto it = commandMap.find(key);
    if (it == commandMap.end()) {
        auto [insert_it, result] = commandMap.insert({key, std::vector<const Command*>()});
        it = result ? insert_it : throw std::runtime_error("Failed to insert command");
    }

    it->second.push_back(command);
}

bool PlayerController::clearKeyCommand(Uint32 key) {
    if (const auto it = commandMap.find(key); it != commandMap.end()) {
        commandMap.erase(it);
        return true;
    }
    return false;
}

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
    if (const auto it = commandMap.find(key); it != commandMap.end()) {
        for (const auto& command : it->second) {
            command->execute();
        }
    }
}
