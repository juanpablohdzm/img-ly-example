//
// Created by Juan Pablo Hernandez Mosti on 22/04/25.
//

#pragma once

#include <random>
#include <__random/random_device.h>

#include "components/ECSManager.h"
#include "components/ECSComponents/Tags/EnemyTag.h"
#include "components/ECSComponents/Speed.h"
#include "components/ECSComponents/Target.h"
#include "components/ECSComponents/Velocity.h"
#include "components/ECSComponents/Collider.h"

#define ENEMY_SPAWN_LIMIT 1000 ///< The maximum number of enemies that can be spawned.
#define ENEMY_SPAWN_RATE 1.0f ///< The time interval (in seconds) between enemy spawns.

/**
 * @struct SpawnEnemySystem
 * @brief A system responsible for spawning enemy entities in the game.
 *
 * The SpawnEnemySystem handles the creation of enemy entities at random positions
 * outside the game window. It ensures that the number of enemies does not exceed
 * the defined spawn limit and spawns enemies at a fixed rate.
 */
struct SpawnEnemySystem {
    /**
     * @brief Updates the enemy spawn system.
     *
     * This function is called periodically to check if new enemies need to be spawned.
     * It uses a timer to control the spawn rate and ensures that the number of enemies
     * does not exceed the defined limit. New enemies are created with random positions
     * and initialized with various components such as EnemyTag, Sprite, Position, Speed,
     * Velocity, and TargetPosition.
     *
     * @param dt The time elapsed since the last update (in seconds).
     */
    static void update(float dt) {
        // persistent variables through iteration
        static float spawnTimer = 0.0f;
        static std::random_device rd;
        static std::mt19937 mt(rd());

        spawnTimer += dt;
        if (spawnTimer < ENEMY_SPAWN_RATE) {
           return;
        }
        spawnTimer = 0.0f;

        auto enemyView = ECSManager::view<EnemyTag>();
        if (enemyView.size() >= ENEMY_SPAWN_LIMIT) {
            return;
        }

        auto entity = ECSManager::create();
        // Randomly generate position within a circle outside the window
        std::uniform_real_distribution<float> posDist(Window::getWidth() * 1.0f, Window::getWidth() * 2.0f);
        std::uniform_real_distribution<float> angleDist(0.0f, 2.0f * M_PI);

        const float radius = posDist(mt);
        const float angle = angleDist(mt);

        const Position position(glm::vec3(cos(angle) * radius, sin(angle) * radius, 0.0f));
        //TODO: Factory pattern for diverse enemies
        ECSManager::emplace<EnemyTag>(entity, EnemyTag());
        ECSManager::emplace<Sprite>(entity, "resource/Hangar/Dot_02.png", position , 65, 65);
        ECSManager::emplace<Position>(entity, position);
        ECSManager::emplace<Speed>(entity, 100.0f);
        ECSManager::emplace<Velocity>(entity, Velocity());
        ECSManager::emplace<Target>(entity, Target());
        ECSManager::emplace<Collider>(entity, 65.0f, 65.0f);
    }
};
