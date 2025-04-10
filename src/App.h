//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//
#pragma once
#include <memory>

class Command;
class SDL_Window;
class SDL_Renderer;
class PlayerController;

class App {
    App() = default;
public:
    App(const App&) = delete;
    App(App&&) = delete;
    App& operator=(const App&) = delete;
    App& operator=(App&&) = delete;

    static int run();
    void quit();
private:

    //Init dependencies
    void initialize();
    // Main loop
    void mainLoop();
    void clearRender() const;
    bool shouldStop() const;

    // End the program
    void destroy() const;

    bool isRunning = false;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    std::unique_ptr<PlayerController> playerController = nullptr;

    std::unique_ptr<Command> quitCommand = nullptr;
};
