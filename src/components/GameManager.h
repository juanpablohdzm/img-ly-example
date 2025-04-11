//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <memory>
#include <entt/entity/registry.hpp>

class Button;
class PlayerController;
class Window;
class Canvas;

enum class GameState {
    DEFAULT,
    MAIN_MENU,
    PLAYING,
};

class GameManager {
public:
    GameManager(entt::registry* registry, Window* window, PlayerController* pc);
    ~GameManager();

    void update(float dt);

    void setCurrentState(GameState state);
    GameState getCurrentState() { return currentState; }

private:
    void initMainMenu();


    Window* window;
    entt::registry* registry;
    PlayerController* playerController;

    GameState currentState;

    std::unique_ptr<Canvas> mainMenuCanvas = nullptr;
    std::unique_ptr<Button> playButton = nullptr;
    std::unique_ptr<Button> quitButton = nullptr;
};



#endif //GAMEMANAGER_H
