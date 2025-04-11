//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#ifndef CANVAS_H
#define CANVAS_H
#include <vector>

class PlayerController;
class Widget;
class Window;

class Canvas {
public:
    Canvas(Window* window, PlayerController* playerController);

    void update(float dt);

private:
    std::vector<Widget*> widgets;

    Window* window;
    PlayerController* playerController;
};



#endif //CANVAS_H
