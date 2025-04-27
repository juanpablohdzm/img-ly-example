//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#pragma once

#include "components/ECSManager.h"
#include "components/ECSComponents/Tags/PlayerTag.h"
#include "components/ECSComponents/Position.h"
#include "components/ECSComponents/Target.h"

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
     *
     * This method first retrieves the player's position by iterating over entities
     * with Position and PlayerTag components. Then, it updates the target position
     * of all entities with a TargetPosition component to match the player's position.
     */
    static void update() {

        // Retrieve the player's position
        Position playerPos {};
        for (auto [entity, pos] : ECSManager::view<Position, PlayerTag>().each()) {
            playerPos = pos;
        }

        // Update the target position of all entities to the player's position
        for (auto [entity, target] : ECSManager::view<Target>().each()) {
            target.value = playerPos.value;
        }
    }
};
