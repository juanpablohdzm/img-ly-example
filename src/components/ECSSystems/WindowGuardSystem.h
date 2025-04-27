//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#pragma once

#include "components/ECSManager.h"
#include "components/Window.h"
#include "components/ECSComponents/WindowGuard.h"

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
     *
     * This method iterates over all entities with Position and WindowGuard components
     * and adjusts their positions to ensure they remain within the window's width and height.
     */
    static void update() {
        for (auto [entity, pos, windowGuard] : ECSManager::view<Position, WindowGuard>().each()) {
            if (pos.value.x < 0) {
                pos.value.x = 0;
            } else if (pos.value.x + windowGuard.width > Window::getWidth()) {
                pos.value.x = Window::getWidth() - windowGuard.width;
            }
            if (pos.value.y < 0) {
                pos.value.y = 0;
            } else if (pos.value.y + windowGuard.height > Window::getHeight()) {
                pos.value.y = Window::getHeight() - windowGuard.height;
            }
        }
    }
};
