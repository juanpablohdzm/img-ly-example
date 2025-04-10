//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//
#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <SDL3/SDL_stdinc.h>

class Command;

using CommandMapType = std::unordered_map<Uint32, std::vector<const Command*>>;

class PlayerController {
public:
    void addKeyCommand(Uint32 key, const Command* command);
    bool clearKeyCommand(Uint32 key);

    template <typename T>
    void addQuitEvent(T* ptr, void(T::*func)());
    template <typename T>
    void removeQuitEvent(const T* ptr);

    void run();
private:
    void executeKeyCommand(Uint32 key);

    CommandMapType commandMap{};
    std::unordered_map<void*, std::function<void()>> quitEvent;
};

template<typename T>
void PlayerController::addQuitEvent(T *ptr, void(T::*func)()) {
    quitEvent[ptr] = [ptr, func]() { (ptr->*func)(); };
}

template<typename T>
void PlayerController::removeQuitEvent(const T *ptr) {
    quitEvent.erase(ptr);
}
