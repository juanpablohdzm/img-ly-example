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
class Sprite;

enum class GameState {
    DEFAULT = 0,
    MAIN_MENU,
    PLAYING,
};

class GameManager {
public:
    GameManager(entt::registry* registry, Window* window, PlayerController* pc);
    ~GameManager();

    void update(float dt);
    void initialize();

    void setCurrentState(GameState state);
    GameState getCurrentState() const { return currentState; }


private:


    Window* window;
    entt::registry* registry;
    PlayerController* playerController;

    GameState currentState;

    std::unique_ptr<Canvas> mainMenuCanvas = nullptr;

};



#endif //GAMEMANAGER_H
