//
// Created by Juan Pablo Hernandez Mosti on 21/04/25.
//

#ifndef UPDATEENEMYVELOCITYSYSTEM_H
#define UPDATEENEMYVELOCITYSYSTEM_H
#include "../ECSManager.h"
#include "../ECSComponents/ECSComponentsGeneral.h"

/**
 * @struct UpdateEnemyVelocitySystem
 * @brief A system that updates the velocity of enemies based on their target positions.
 *
 * The UpdateEnemyVelocitySystem is responsible for calculating the velocity
 * of entities with Velocity, Position, and TargetPosition components. It adjusts
 * the velocity to point towards the target position.
 */
struct UpdateEnemyVelocitySystem {
    /**
     * @brief Updates the velocity of entities to move towards their target positions.
     *
     * This method iterates over all entities with Velocity, Position, and TargetPosition
     * components and calculates the velocity vector required to move the entity
     * towards its target position.
     */
    static void update() {
        for (auto [entity, vel, pos, targetPos] : ECSManager::view<Velocity, Position, TargetPosition>().each()) {
            vel.dx = targetPos.x - pos.x;
            vel.dy = targetPos.y - pos.y;
        }
    }
};

#endif //UPDATEENEMYVELOCITYSYSTEM_H