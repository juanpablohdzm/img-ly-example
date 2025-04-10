//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <entt/entity/registry.hpp>

#include "PlayerController.h"

class PlayerController;
class Window;

enum class GameState {
    DEFAULT,
    MAIN_MENU,
    PLAYING,
};

class GameManager {
public:
    GameManager(entt::registry* registry, Window* window, PlayerController* pc);

    void update(float dt);

    GameState getCurrentState() { return currentState; }


    void setCurrentState(GameState state);

private:
    void initMainMenu();


    Window* window;
    entt::registry* registry;
    PlayerController* playerController;

    GameState currentState;
};



#endif //GAMEMANAGER_H
