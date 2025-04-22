//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#ifndef WINDOWGUARDSYSTEM_H
#define WINDOWGUARDSYSTEM_H

#include "../ECSManager.h"
#include "../ECSComponents/ECSComponentsGeneral.h"
#include "../Window.h"

/**
 * @struct WindowGuardSystem
 * @brief A system that ensures entities with a WindowGuard component stay within the window boundaries.
 *
 * The WindowGuardSystem is responsible for clamping the position of entities
 * to ensure they do not move outside the defined window dimensions. It operates
 * on entities with both Position and WindowGuard components.
 */
struct WindowGuardSystem {
    /**
     * @brief Updates the positions of entities to keep them within the window boundaries.
     * @param dt The time elapsed since the last update, in seconds.
     *
     * This method iterates over all entities with Position and WindowGuard components
     * and adjusts their positions to ensure they remain within the window's width and height.
     */
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