//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#ifndef WINDOWBACKGROUND_H
#define WINDOWBACKGROUND_H
#include <entt/entt.hpp>

class Window;

class WindowBackground {
public:
    WindowBackground(std::weak_ptr<entt::registry> registry, const std::weak_ptr<Window>& window);

private:
    std::weak_ptr<Window> window;
    std::weak_ptr<entt::registry> registry;
};



#endif //WINDOWBACKGROUND_H
