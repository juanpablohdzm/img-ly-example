//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//
#pragma once
#include <unordered_map>
#include <unordered_set>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_stdinc.h>

#include "../components/ECSComponents/PositionComp.h"


class PlayerController {
public:
    template <typename T>
    void addKeyCallback(Uint32 key, T* ptr, void(T::*func)(const SDL_Event&));
    template <typename T>
    void addKeyCallback(Uint32 key, T* ptr, std::function<void(const SDL_Event&)> func);
    template <typename T>
    bool clearKeyCallback(Uint32 key, T* ptr);

    template <typename T>
    void addQuitEvent(T* ptr, void(T::*func)());
    template <typename T>
    void addQuitEvent(T* ptr, std::function<void()> func);
    template <typename T>
    void removeQuitEvent(const T* ptr);

    void update(float dt);

    static Position getMousePosition();
private:
    void executeKeyCommand(const SDL_Event& event);

    std::unordered_map<Uint32, std::unordered_map<void*, std::function<void(const SDL_Event&)>>> keyEvents;
    std::unordered_map<void*, std::function<void()>> quitEvent;
};

template<typename T>
void PlayerController::addKeyCallback(Uint32 key, T *ptr, void(T::*func)(const SDL_Event&)) {
    keyEvents[key].insert({ptr, [ptr, func](const SDL_Event& event) {(ptr->*func)(event);}});
}

template<typename T>
void PlayerController::addKeyCallback(Uint32 key, T *ptr, std::function<void(const SDL_Event&)> func) {
    keyEvents[key].insert({ptr, func});
}

template<typename T>
bool PlayerController::clearKeyCallback(Uint32 key, T *ptr) {
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
void PlayerController::addQuitEvent(T *ptr, std::function<void()> func) {
    quitEvent.insert({ptr, func});
}

template<typename T>
void PlayerController::removeQuitEvent(const T *ptr) {
    quitEvent.erase(ptr);
}
