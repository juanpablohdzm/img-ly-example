//
// Created by Juan Pablo Hernandez Mosti on 18/04/25.
//

#pragma once

/**
 * @struct WindowGuard
 * @brief A component that defines the boundaries of a sprite.
 *
 * The WindowGuard component is used to specify the width and height
 * of a sprite, which can be used to constrain or manage
 * entities within the boundaries of the window.
 */
struct WindowGuard {
    float width;  ///< The width of the sprite.
    float height; ///< The height of the sprite.
};
