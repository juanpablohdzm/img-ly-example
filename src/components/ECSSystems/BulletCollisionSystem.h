//
// Created by Juan Pablo Hernandez Mosti on 28/04/25.
//

#pragma once

#include "components/ECSManager.h"
#include "components/ECSComponents/Position.h"
#include "components/ECSComponents/Collider.h"
#include "components/ECSComponents/Tags/BulletTag.h"
#include "components/ECSComponents/Tags/EnemyTag.h"
#include "components/ECSComponents/Tags/DespawnTag.h"

/**
 * @brief System responsible for handling collisions between bullets and enemies.
 */
struct BulletCollisionSystem {
  /**
   * @brief Updates collision detection between bullet and enemy entities.
   *
   * Iterates over entities with Position, Collider, and BulletTag (excluding those with DespawnTag),
   * and checks for collisions with entities having Position, Collider, and EnemyTag (excluding those with DespawnTag).
   * If a collision is detected, both entities are marked for despawn.
   */
  static void update() {
      for (auto [entity, position, collider] : ECSManager::view<Position, Collider, BulletTag>(entt::exclude_t<DespawnTag>()).each()) {
            for (auto [otherEntity, otherPosition, otherCollider] : ECSManager::view<Position, Collider, EnemyTag>(entt::exclude_t<DespawnTag>()).each()) {
                if (intersects(position, collider, otherPosition, otherCollider)) {
                    ECSManager::emplace<DespawnTag>(otherEntity, DespawnTag());
                    ECSManager::emplace<DespawnTag>(entity, DespawnTag());
                    GameManager::addScorePoint(1);
                }
            }
      }
  }

private:
  /**
   * @brief Determines if two entities intersect based on their positions and colliders.
   *
   * @param p0 Position of the first entity.
   * @param c0 Collider of the first entity.
   * @param p1 Position of the second entity.
   * @param c1 Collider of the second entity.
   * @return True if the entities intersect, false otherwise.
   */
  bool static intersects(const Position &p0, const Collider &c0,
                const Position &p1, const Collider &c1) {
    return !(p0.value.x + c1.width  < p1.value.x ||
             p1.value.x + c1.width  < p0.value.x ||
             p0.value.y + c0.height  < p1.value.y ||
             p1.value.y + c1.height  < p0.value.y);
  }
};
