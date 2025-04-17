//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <memory>
#include "../utils/Singleton.h"

class Character;
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

class GameManager : public Singleton<GameManager> {
    friend class Singleton<GameManager>;
    GameManager();
public:
    static void initialize( PlayerController* pc);
    ~GameManager();

    static void update(float dt);

    static void setCurrentState(GameState state);
    static GameState getCurrentState() { return getInstance()->currentState; }


private:

    PlayerController* playerController;

    GameState currentState;

    std::unique_ptr<Canvas> mainMenuCanvas = nullptr;
    std::unique_ptr<Canvas> gameHud = nullptr;
    std::unique_ptr<Character> playerCharacter = nullptr;

};



#endif //GAMEMANAGER_H
