//
// Created by Juan Pablo Hernandez Mosti on 21/04/25.
//

#pragma once

/**
 * @struct Target
 * @brief A component that represents the target position of an entity.
 *
 * The TargetPosition component stores the vec3 coordinates of a target
 * location. It is typically used in systems that handle movement or AI
 * behavior to guide entities toward a specific point.
 */
struct Target {
    glm::vec3 value; ///< The target position of the entity.
};
