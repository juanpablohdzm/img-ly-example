//
// Created by Juan Pablo Hernandez Mosti on 28/04/25.
//

#pragma once

#include "components/ECSManager.h"
#include "components/ECSComponents/Position.h"
#include "components/ECSComponents/Collider.h"
#include "components/ECSComponents/Tags/EnemyTag.h"
#include "components/ECSComponents/Tags/PlayerTag.h"
#include "components/ECSComponents/Tags/DespawnTag.h"
#include "components/GameManager.h"


/**
 * @brief System responsible for handling collisions between player and enemies.
 */
struct EnemyCollisionSystem {
    /**
     * @brief Updates collision detection between the player and enemy entities.
     *
     * Iterates over entities with Position, Collider, and EnemyTag (excluding those with DespawnTag),
     * and checks for collisions Position, Collider, and PlayerTag (excluding those with DespawnTag).
     * If a collision is detected, on hit player is executed.
     */
    static void update() {
        for (auto [entity, position, collider] : ECSManager::view<Position, Collider, EnemyTag>(entt::exclude_t<DespawnTag>()).each()) {
            for (auto [otherEntity, otherPosition, otherCollider] : ECSManager::view<Position, Collider, PlayerTag>(entt::exclude_t<DespawnTag>()).each()) {
                if (intersects(position, collider, otherPosition, otherCollider)) {
                   GameManager::onPlayerHit();
                   break;
                }
            }
        }
    }

private:
    /**
     * @brief Determines if two entities intersect based on their positions and colliders.
     *
     * @param p0 Position of the first entity.
     * @param c0 Collider of the first entity.
     * @param p1 Position of the second entity.
     * @param c1 Collider of the second entity.
     * @return True if the entities intersect, false otherwise.
     */
    bool static intersects(const Position &p0, const Collider &c0,
                  const Position &p1, const Collider &c1) {
        return !(p0.value.x + c1.width  < p1.value.x ||
                 p1.value.x + c1.width  < p0.value.x ||
                 p0.value.y + c0.height  < p1.value.y ||
                 p1.value.y + c1.height  < p0.value.y);
    }
};