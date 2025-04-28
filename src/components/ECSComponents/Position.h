//
// Created by Juan Pablo Hernandez Mosti on 27/04/25.
//

#pragma once

#include <glm/vec3.hpp>

/**
 * @brief Structure for representing a position component in the ECS.
 *
 * This structure encapsulates the position value used by entities.
 */
struct Position {
  glm::vec3 value; ///< The current position value.
};
