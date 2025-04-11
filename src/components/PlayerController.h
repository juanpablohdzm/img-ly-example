//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//
#pragma once
#include <unordered_map>
#include <unordered_set>
#include <SDL3/SDL_stdinc.h>


class PlayerController {
public:
    template <typename T>
    void addKeyCallback(Uint32 key, T* ptr, void(T::*func)());
    template <typename T>
    bool clearKeyCallback(Uint32 key, const T* ptr);

    template <typename T>
    void addQuitEvent(T* ptr, void(T::*func)());
    template <typename T>
    void removeQuitEvent(const T* ptr);

    void run();
private:
    void executeKeyCommand(Uint32 key);

    std::unordered_map<Uint32, std::unordered_map<void*, std::function<void()>>> keyEvents;
    std::unordered_map<void*, std::function<void()>> quitEvent;
};

template<typename T>
void PlayerController::addKeyCallback(Uint32 key, T *ptr, void(T::*func)()) {
    keyEvents[key].insert({ptr, [ptr, func]() {(ptr->*func)();}});
}

template<typename T>
bool PlayerController::clearKeyCallback(Uint32 key, const T *ptr) {
    if (auto it = keyEvents.find(key); it != keyEvents.end()) {
        auto& callbacks = it->second;
        callbacks.erase(ptr);
        return true;
    }
    return false;
}

template<typename T>
void PlayerController::addQuitEvent(T *ptr, void(T::*func)()) {
    quitEvent.insert({ptr, [ptr, func](){(ptr->*func)();}});
}

template<typename T>
void PlayerController::removeQuitEvent(const T *ptr) {
    quitEvent.erase(ptr);
}
