//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//
#pragma once
#include <memory>
#include <entt/entt.hpp>

class Command;
class SDL_Window;
class Window;
class WindowBackground;
class SDL_Renderer;
class PlayerController;
class GameManager;

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
    [[nodiscard]] bool shouldStop() const;

    // End the program
    void destroy() const;

    bool isRunning = false;

    // Dependencies
    std::unique_ptr<Window> window = nullptr;
    std::unique_ptr<PlayerController> playerController = nullptr;
    std::unique_ptr<entt::registry> registry = nullptr;
    std::unique_ptr<WindowBackground> windowBackground = nullptr;
    std::unique_ptr<GameManager> gameManager = nullptr;

    // Commands
    std::unique_ptr<Command> quitCommand = nullptr;
};
