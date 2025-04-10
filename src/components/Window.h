//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#ifndef WINDOW_H
#define WINDOW_H
#include <functional>


class SDL_Window;
class SDL_Renderer;

struct WindowColor {
    int r;
    int g;
    int b;
    int a;
};

class Window {
public:
    Window(const char* title, int width, int height, WindowColor color = {0, 0, 0, 255});
    virtual ~Window();

    void clearWindow() const;
    template <typename T, typename RetValue, typename ...Args>
    RetValue executeRendererAction(T* ptr, RetValue(T::*action)(SDL_Renderer*, Args...), Args&&... args) const;
    void presentRender() const;
private:
    WindowColor color;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};

template<typename T, typename RetValue, typename ...Args>
RetValue Window::executeRendererAction(T *ptr, RetValue(T::*action)(SDL_Renderer *, Args...), Args&&... args) const {
    return (ptr->*action)(renderer, std::forward<Args>(args)...);
}


#endif //WINDOW_H
