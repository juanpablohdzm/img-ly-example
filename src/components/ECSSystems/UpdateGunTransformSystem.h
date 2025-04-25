//
// Created by Juan Pablo Hernandez Mosti on 22/04/25.
//

#ifndef UPDATEGUNTRANSFORMSYSTEM_H
#define UPDATEGUNTRANSFORMSYSTEM_H
#include "../ECSManager.h"
#include "../PlayerController.h"
#include "../ECSComponents/GunTag.h"
#include "../ECSComponents/PositionComp.h"
#include "../ECSComponents/PlayerTag.h"
#include "../ui/Sprite.h"

/**
* @struct UpdateGunTransformSystem
* @brief A system responsible for updating the position of gun entities relative to the player.
*
* The UpdateGunTransformSystem adjusts the position of gun entities based on the player's
* position and the mouse cursor's location. It ensures that the gun is positioned at a fixed
* offset from the player and rotates to face the mouse cursor.
*/
struct UpdateGunTransformSystem {
/**
 * @brief Updates the gun transform system.
 *
 * This function is called periodically to update the position of gun entities.
 * It calculates the player's position and dimensions, determines the angle between
 * the player and the mouse cursor, and adjusts the gun's position accordingly.
 *
 */
static void update() {

    Position playerPos {0, 0}; ///< The position of the player.
    float playerWidth = 0.0f; ///< The width of the player's sprite.
    float playerHeight = 0.0f; ///< The height of the player's sprite.

    // Retrieve the player's position and dimensions.
    for (auto [entity, pos, sprite] : ECSManager::view<Position, Sprite, PlayerTag>().each()) {
        playerPos = pos;
        playerWidth = sprite.getWidth();
        playerHeight = sprite.getHeight();
    }

    // Get the current mouse position.
    const auto [mouseX, mouseY] = PlayerController::getMousePosition();

    constexpr float radiusOffset = 70.0f; ///< The offset distance for the gun's position.

    // Update the position of each gun entity.
    for (auto [entity, pos, sprite] : ECSManager::view<Position, Sprite, GunTag>().each()) {
        const float angle =  std::atan2f(mouseY - playerPos.y, mouseX - playerPos.x);


        sprite.setAngleRotation(angle * 180.0f / M_PI + 90.0f);
        pos.x = playerPos.x + playerWidth * 0.25f + cos(angle) * radiusOffset;
        pos.y = playerPos.y + playerHeight * 0.25f + sin(angle) * radiusOffset;
    }
}
};

#endif //UPDATEGUNTRANSFORMSYSTEM_H