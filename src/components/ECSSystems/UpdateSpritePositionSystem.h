//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#pragma once

#include "components/ECSManager.h"
#include "components/ui/Sprite.h"

/**
 * @struct UpdateSpritePositionSystem
 * @brief A system that synchronizes sprite positions with their corresponding entity positions.
 *
 * The UpdateSpritePositionSystem is responsible for updating the position of sprites
 * based on the position components of their associated entities. It operates on entities
 * that have both Position and Sprite components.
 */
struct UpdateSpritePositionSystem {
    /**
     * @brief Updates the positions of sprites to match their associated entity positions.
     *
     * This method iterates over all entities with Position and Sprite components
     * and updates the sprite's position to reflect the entity's current position.
     */
    static void update() {
        for (auto [entity, pos, sprite] : ECSManager::view<Position, Sprite>().each()) {
                sprite.updatePosition(pos);
        }
    }
};
