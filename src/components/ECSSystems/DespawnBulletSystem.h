//
// Created by Juan Pablo Hernandez Mosti on 22/04/25.
//

#ifndef DESPAWNBULLETSYSTEM_H
#define DESPAWNBULLETSYSTEM_H
#include "../ECSManager.h"
#include "../Window.h"
#include "../ECSComponents/BulletTag.h"
#include "../ECSComponents/DespawnTag.h"
#include "../ECSComponents/PositionComp.h"

/**
 * @struct DespawnBulletSystem
 * @brief A system responsible for marking bullets for despawning when they move outside the window boundaries.
 *
 * This system iterates over all entities with both the Position and BulletTag components.
 * If an entity's position is outside the window's dimensions, it adds a DespawnTag component
 * to the entity, marking it for removal.
 */
struct DespawnBulletSystem {
    /**
     * @brief Updates the system and marks bullets for despawning if they are out of bounds.
     *
     * This function retrieves all entities with Position and BulletTag components,
     * checks their positions against the window boundaries, and adds a DespawnTag
     * component to entities that are out of bounds.
     */
    static void update() {
        for (auto [entity, pos] : ECSManager::view<Position, BulletTag>(entt::exclude_t<DespawnTag>()).each()) {
            const float windowWidth = Window::getWidth();
            const float windowHeight = Window::getHeight();


            if (pos.x < 0 || pos.x > windowWidth || pos.y < 0 || pos.y > windowHeight) {
                    ECSManager::emplace<DespawnTag>(entity, DespawnTag());
            }
        }
    }
};

#endif //DESPAWNBULLETSYSTEM_H