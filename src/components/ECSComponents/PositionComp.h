//
// Created by Juan Pablo Hernandez Mosti on 18/04/25.
//

#ifndef POSITIONCOMP_H
#define POSITIONCOMP_H

/**
 * @struct Position
 * @brief A component that represents the position of an entity in 2D space.
 *
 * The Position component stores the x and y coordinates of an entity.
 * It is typically used in systems that handle rendering, movement, or
 * spatial calculations.
 */
struct Position {
    float x; ///< The x-coordinate of the entity's position.
    float y; ///< The y-coordinate of the entity's position.
};

#endif //POSITIONCOMP_H