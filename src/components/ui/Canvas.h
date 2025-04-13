//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#ifndef CANVAS_H
#define CANVAS_H
#include <unordered_set>
#include <vector>
#include <SDL3/SDL_events.h>

class GameManager;
class PlayerController;
class Widget;
class Window;

class Canvas {
public:
    Canvas(Window* window, PlayerController* playerController, GameManager* gameManager);
    virtual ~Canvas();

    virtual void update(float dt);
    virtual void addChild(Widget* widget);
    virtual void removeChild(Widget* widget);
    virtual void initialize();

protected:

    void onMouseClicked(const SDL_Event& event);
    std::unordered_set<Widget*> widgets;

    Window* window = nullptr;
    PlayerController* playerController = nullptr;
    GameManager* gameManager = nullptr;
    Widget* focusedWidget = nullptr;
};
#endif //CANVAS_H
