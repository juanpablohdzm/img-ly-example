//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#ifndef WINDOW_H
#define WINDOW_H
#include <functional>
#include "../utils/Color.h"
#include "../utils/Singleton.h"


class SDL_Window;
class SDL_Renderer;


class Window final : public Singleton<Window> {
    friend class Singleton<Window>;
    Window();
public:
    static void initialize(const char* title, int width, int height,const Color& color = {0, 0, 0, 255});
    static void clearWindow();
    static void presentRender();
    ~Window();

    [[nodiscard]] static int getWidth() { return getInstance()->width; }
    [[nodiscard]] static int getHeight() { return getInstance()->height; }
    [[nodiscard]] static SDL_Renderer* getRenderer() { return getInstance()->renderer; }
private:
    Color color;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    int width, height;
};
#endif //WINDOW_H