//
// Created by Juan Pablo Hernandez Mosti on 18/04/25.
//

#ifndef VELOCITYCOMP_H
#define VELOCITYCOMP_H

/**
 * @struct Velocity
 * @brief A component that represents the velocity of an entity.
 *
 * The Velocity component stores the directional movement of an entity
 * in terms of its x and y components. It is typically used in systems
 * that handle movement or physics calculations.
 */
struct Velocity {
    float dx; ///< The velocity in the x-direction.
    float dy; ///< The velocity in the y-direction.
};

#endif //VELOCITYCOMP_H