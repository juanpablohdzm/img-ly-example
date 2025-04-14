//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//
#pragma once
#include <memory>
#include <entt/entt.hpp>
#include <SDL3/SDL_events.h>

#include "utils/Singleton.h"

class SDL_Window;
class Window;
class WindowBackground;
class SDL_Renderer;
class PlayerController;
class GameManager;

class App final : public Singleton<App> {
    friend class Singleton<App>;
    App();
public:

    static int run();
    static void exit();

    void quit();
    void quit(const SDL_Event& event);
private:

    bool isRunning = false;
    //Init dependencies
    void initialize();
    // Main loop
    void mainLoop();

    // Dependencies
    std::unique_ptr<PlayerController> playerController = nullptr;
};
