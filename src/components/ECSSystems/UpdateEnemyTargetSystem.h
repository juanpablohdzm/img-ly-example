//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#ifndef ENEMYVELOCITYSYSTEM_H
#define ENEMYVELOCITYSYSTEM_H

#include "../ECSManager.h"
#include "../ECSComponents/ECSComponentsGeneral.h"

/**
 * @struct UpdateEnemyTargetSystem
 * @brief A system that updates the target position of enemies to follow the player's position.
 *
 * The UpdateEnemyTargetSystem is responsible for setting the target position of entities
 * with a TargetPosition component to match the current position of the player. It operates
 * on entities with Position and PlayerTag components to determine the player's position.
 */
struct UpdateEnemyTargetSystem {
    /**
     * @brief Updates the target positions of enemies to follow the player's position.
     * @param dt The time elapsed since the last update, in seconds.
     *
     * This method first retrieves the player's position by iterating over entities
     * with Position and PlayerTag components. Then, it updates the target position
     * of all entities with a TargetPosition component to match the player's position.
     */
    static void update(float dt) {

        // Retrieve the player's position
        Position playerPos {0, 0};
        for (auto [entity, pos] : ECSManager::view<Position, PlayerTag>().each()) {
            playerPos = pos;
        }

        // Update the target position of all entities to the player's position
        for (auto [entity, target] : ECSManager::view<TargetPosition>().each()) {
            target.x = playerPos.x;
            target.y = playerPos.y;
        }
    }
};

#endif //ENEMYVELOCITYSYSTEM_H