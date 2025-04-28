//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//
#pragma once

#include <unordered_map>
#include <unordered_set>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_stdinc.h>

struct Position;
/**
 * @class PlayerController
 * @brief Manages player input and event handling.
 *
 * The PlayerController class provides functionality to register and execute
 * key event callbacks and quit event callbacks. It also tracks the mouse position.
 */
class PlayerController {
public:
    /**
     * @brief Adds a key event callback for a specific key.
     *
     * @tparam T The type of the object containing the callback method.
     * @param key The SDL key code to associate with the callback.
     * @param ptr A pointer to the object containing the callback method.
     * @param func A member function pointer to the callback method.
     */
    template <typename T>
    void addKeyCallback(Uint32 key, T* ptr, void(T::*func)(const SDL_Event&));

    /**
     * @brief Adds a key event callback for a specific key using a std::function.
     *
     * @tparam T The type of the object containing the callback.
     * @param key The SDL key code to associate with the callback.
     * @param ptr A pointer to the object containing the callback.
     * @param func A std::function representing the callback.
     */
    template <typename T>
    void addKeyCallback(Uint32 key, T* ptr, std::function<void(const SDL_Event&)> func);

    /**
     * @brief Removes a key event callback for a specific key.
     *
     * @tparam T The type of the object containing the callback.
     * @param key The SDL key code associated with the callback.
     * @param ptr A pointer to the object containing the callback.
     * @return True if the callback was removed, false otherwise.
     */
    template <typename T>
    bool clearKeyCallback(Uint32 key, T* ptr);

    /**
     * @brief Adds a quit event callback.
     *
     * @tparam T The type of the object containing the callback method.
     * @param ptr A pointer to the object containing the callback method.
     * @param func A member function pointer to the callback method.
     */
    template <typename T>
    void addQuitEvent(T* ptr, void(T::*func)());

    /**
     * @brief Adds a quit event callback using a std::function.
     *
     * @tparam T The type of the object containing the callback.
     * @param ptr A pointer to the object containing the callback.
     * @param func A std::function representing the callback.
     */
    template <typename T>
    void addQuitEvent(T* ptr, std::function<void()> func);

    /**
     * @brief Removes a quit event callback.
     *
     * @tparam T The type of the object containing the callback.
     * @param ptr A pointer to the object containing the callback.
     */
    template <typename T>
    void removeQuitEvent(const T* ptr);

    /**
     * @brief Updates the player controller state.
     *
     * This function processes input events and executes the associated callbacks.
     *
     */
    void update();

    /**
     * @brief Gets the current mouse position.
     *
     * @return A Position object representing the mouse position.
     */
    static Position getMousePosition();

    /**
     * @brief Toggles the cursor visibility.
     *
     * Enables or disables the cursor based on the provided flag.
     *
     * @param isEnabled If true, the cursor is enabled; if false, it is disabled.
     */
    static void toggleCursor(bool isEnabled);

private:
    /**
     * @brief Executes the key command associated with an SDL event.
     *
     * @param event The SDL event containing the key information.
     */
    void executeKeyCommand(const SDL_Event& event);

    std::unordered_map<Uint32, std::unordered_map<void*, std::function<void(const SDL_Event&)>>> keyEvents; ///< Map of key events and their callbacks.
    std::unordered_map<void*, std::function<void()>> quitEvent; ///< Map of quit events and their callbacks.
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