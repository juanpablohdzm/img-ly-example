//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#ifndef CANVAS_H
#define CANVAS_H
#include <unordered_set>
#include <vector>
#include <SDL3/SDL_events.h>

class PlayerController;
class Widget;
class Window;

class Canvas {
public:
    Canvas(Window* window, PlayerController* playerController);
    virtual ~Canvas();

    void update(float dt);
    void addChild(Widget* widget);
    void removeChild(Widget* widget);

private:

    void onMouseClicked(const SDL_Event& event);
    std::unordered_set<Widget*> widgets;

    Window* window = nullptr;
    PlayerController* playerController = nullptr;
    Widget* focusedWidget = nullptr;
};
#endif //CANVAS_H
