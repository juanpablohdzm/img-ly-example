//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#ifndef CLICKABLE_H
#define CLICKABLE_H

/**
 * @class Clickable
 * @brief An interface for objects that can be clicked.
 *
 * The Clickable class defines a pure virtual interface for objects
 * that need to implement click functionality. Any class inheriting
 * from Clickable must provide an implementation for the click method.
 */
class Clickable {
public:
    /**
     * @brief Virtual destructor for the Clickable interface.
     *
     * Ensures proper cleanup of derived classes.
     */
    virtual ~Clickable() = default;

    /**
     * @brief Pure virtual method to handle click events.
     *
     * Classes inheriting from Clickable must implement this method
     * to define the behavior when the object is clicked.
     */
    virtual void click() = 0;
};

#endif //CLICKABLE_H