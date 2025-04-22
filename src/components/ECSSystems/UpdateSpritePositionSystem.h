//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#ifndef UPDATESPRITEPOSITIONSYSTEM_H
#define UPDATESPRITEPOSITIONSYSTEM_H

#include "../ECSManager.h"
#include "../ui/Sprite.h"

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
     * @param dt The time elapsed since the last update, in seconds.
     *
     * This method iterates over all entities with Position and Sprite components
     * and updates the sprite's position to reflect the entity's current position.
     */
    static void update(float dt) {
        for (auto [entity, pos, sprite] : ECSManager::view<Position, Sprite>().each()) {
                sprite.updatePosition(pos);
        }
    }
};

#endif //UPDATESPRITEPOSITIONSYSTEM_H