//
// Created by Juan Pablo Hernandez Mosti on 18/04/25.
//

#pragma once

#include <glm/vec3.hpp>

/**
 * @struct Velocity
 * @brief A component that represents the velocity of an entity.
 *
 * The Velocity component stores the directional movement of an entity
 * in terms of a vector. It is typically used in systems
 * that handle movement or physics calculations.
 */
struct Velocity {
    glm::vec3 value;
};
