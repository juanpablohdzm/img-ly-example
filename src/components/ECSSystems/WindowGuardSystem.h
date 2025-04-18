//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#ifndef WINDOWGUARDSYSTEM_H
#define WINDOWGUARDSYSTEM_H

#include "../ECSManager.h"
#include "../ECSComponents/ECSComponentsGeneral.h"
#include "../Window.h"


struct WindowGuardSystem {
    static void update(float dt) {
        for (auto [entity, pos, windowGuard] : ECSManager::view<Position, WindowGuard>().each()) {
            if (pos.x < 0) {
                pos.x = 0;
            } else if (pos.x + windowGuard.width > Window::getWidth()) {
                pos.x = Window::getWidth() - windowGuard.width;
            }
            if (pos.y < 0) {
                pos.y = 0;
            } else if (pos.y + windowGuard.height > Window::getHeight()) {
                pos.y = Window::getHeight() - windowGuard.height;
            }
        }
    }
};



#endif //WINDOWGUARDSYSTEM_H
