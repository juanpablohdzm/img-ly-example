//
// Created by Juan Pablo Hernandez Mosti on 22/04/25.
//

#pragma once

#include "components/ECSManager.h"
#include "components/ECSComponents/Tags/DespawnTag.h"

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
     *
     * This function retrieves all entities with the DespawnTag component
     * using the ECSManager's view function and destroys them in bulk.
     */
    static void update() {
        auto view = ECSManager::view<DespawnTag>();
        ECSManager::destroy(view.begin(), view.end());
    }
};
