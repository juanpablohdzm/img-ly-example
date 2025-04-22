//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#ifndef MOVESYSTEM_H
#define MOVESYSTEM_H

#include "../ECSManager.h"
#include "../ECSComponents/ECSComponentsGeneral.h"
#include <cmath>

/**
 * @struct MoveSystem
 * @brief Processes movement of entities based on their velocity and speed.
 *
 * The MoveSystem updates each entity that has Position, Velocity, and Speed
 * components. It normalizes the velocity vector and then updates the entity's
 * position based on the normalized velocity, elapsed time, and the speed value.
 */
struct MoveSystem {
    /**
     * @brief Updates positions of entities according to their velocity and speed.
     * @param dt Time elapsed since the last update, in seconds.
     *
     * This method iterates over all entities having both Position, Velocity,
     * and Speed components. It first normalizes the velocity vector (if non-zero)
     * and then applies movement by incrementing the position components.
     */
    static void update(float dt) {
        for (auto [entity, pos, vel, speed] : ECSManager::view<Position, Velocity, Speed>().each()) {
            const float magnitude = std::sqrt(vel.dx * vel.dx + vel.dy * vel.dy);
            if (magnitude > 0) {
                vel.dx /= magnitude;
                vel.dy /= magnitude;
            }
            pos.x += vel.dx * dt * speed.value;
            pos.y += vel.dy * dt * speed.value;
        }
    }
};

#endif //MOVESYSTEM_H