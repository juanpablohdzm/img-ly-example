//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#ifndef CANVAS_H
#define CANVAS_H
#include <unordered_set>
#include <SDL3/SDL_events.h>

class PlayerController;
class Widget;

class Canvas {
public:
    Canvas(PlayerController* playerController);
    virtual ~Canvas();

    virtual void update(float dt);
    virtual void addChild(Widget* widget);
    virtual void removeChild(Widget* widget);
    virtual void initialize();

protected:

    void onMouseClicked(const SDL_Event& event);
    std::unordered_set<Widget*> widgets;

    PlayerController* playerController = nullptr;
    Widget* focusedWidget = nullptr;
};
#endif //CANVAS_H
