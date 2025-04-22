//
// Created by Juan Pablo Hernandez Mosti on 22/04/25.
//

#ifndef DESPAWNENTITIESSYSTEM_H
#define DESPAWNENTITIESSYSTEM_H
#include "../ECSManager.h"
#include "../ECSComponents/DespawnTag.h"

/**
* @struct DespawnEntitiesSystem
* @brief A system responsible for removing entities marked with the DespawnTag component.
*
* This system iterates over all entities that have the DespawnTag component
* and destroys them. It is typically used to clean up entities that are no
* longer needed in the game world.
*/
struct DespawnEntitiesSystem {
    /**
     * @brief Updates the system and removes entities with the DespawnTag component.
     *
     * @param dt The delta time since the last update (unused in this system).
     *
     * This function retrieves all entities with the DespawnTag component
     * using the ECSManager's view function and destroys them in bulk.
     */
    static void update(float dt) {
        auto view = ECSManager::view<DespawnTag>();
        std::vector<entt::entity> toKill;
        toKill.reserve( view.size<size_t>());

        for (auto e : view) {
            toKill.push_back(e);
        }

        // 2) destroy them one‑by‑one
        ECSManager::destroy(toKill.begin(), toKill.end());
    }
};

#endif //DESPAWNENTITIESSYSTEM_H