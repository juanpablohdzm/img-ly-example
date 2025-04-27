//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#pragma once

#include <glm/glm.hpp>

#include "components/ECSManager.h"
#include "components/ECSComponents/Speed.h"
#include "components/ECSComponents/Velocity.h"
#include "components/ECSComponents/Position.h"

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
            const auto normalizedVelocity = normalize(vel.value);
            pos.value += normalizedVelocity * dt * speed.value;
        }
    }
};
