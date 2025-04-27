//
// Created by Juan Pablo Hernandez Mosti on 20/04/25.
//

#pragma once

#include "components/ECSManager.h"
#include "components/ui/Sprite.h"

/**
 * @struct SpriteRenderSystem
 * @brief A system responsible for rendering sprites associated with entities.
 *
 * The SpriteRenderSystem iterates over all entities with a Sprite component
 * and calls their render method to display them on the screen.
 */
struct SpriteRenderSystem  {
    /**
     * @brief Renders all sprites associated with entities.
     *
     * This method iterates over all entities with a Sprite component
     * and invokes the render method of each sprite to draw it.
     */
    static void update() {
        for (auto [entity, sprite] : ECSManager::view<Sprite>().each()) {
            sprite.render();
        }
    }
};
