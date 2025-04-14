//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#ifndef WINDOW_H
#define WINDOW_H
#include <functional>
#include "../utils/common.h"


class SDL_Window;
class SDL_Renderer;


class Window {
public:
    Window(const char* title, int width, int height, Color color = {0, 0, 0, 255});
    virtual ~Window();

    void clearWindow() const;
    void presentRender() const;

    [[nodiscard]] int getWidth() const { return width; }
    [[nodiscard]] int getHeight() const { return height; }
    [[nodiscard]] SDL_Renderer* getRenderer() const { return renderer; }
private:
    Color color;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    int width, height;
};
#endif //WINDOW_H