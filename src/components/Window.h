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
    friend class Canvas;

public:
    Window(const char* title, int width, int height, Color color = {0, 0, 0, 255});
    virtual ~Window();

    void clearWindow() const;
    template <typename T, typename RetValue, typename ...Args>
    RetValue executeRendererAction(T* ptr, RetValue(T::*action)(SDL_Renderer*, Args...), Args&&... args) const;
    void executeRendererAction(const std::function<void(SDL_Renderer*)>& action) const;
    void presentRender() const;

    [[nodiscard]] int getWidth() const { return width; }
    [[nodiscard]] int getHeight() const { return height; }
private:
    Color color;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    int width, height;
};

template<typename T, typename RetValue, typename ...Args>
RetValue Window::executeRendererAction(T *ptr, RetValue(T::*action)(SDL_Renderer *, Args...), Args&&... args) const {
    return (ptr->*action)(renderer, std::forward<Args>(args)...);
}


#endif //WINDOW_H
