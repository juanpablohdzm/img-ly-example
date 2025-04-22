//
// Created by Juan Pablo Hernandez Mosti on 21/04/25.
//

#ifndef TARGETPOSITION_H
#define TARGETPOSITION_H

/**
 * @struct TargetPosition
 * @brief A component that represents the target position of an entity.
 *
 * The TargetPosition component stores the x and y coordinates of a target
 * location. It is typically used in systems that handle movement or AI
 * behavior to guide entities toward a specific point.
 */
struct TargetPosition {
    float x; ///< The x-coordinate of the target position.
    float y; ///< The y-coordinate of the target position.
};

#endif //TARGETPOSITION_H