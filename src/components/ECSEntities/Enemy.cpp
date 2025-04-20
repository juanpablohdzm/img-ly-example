//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#include "Enemy.h"
#include "../ECSManager.h"
#include "../ui/Sprite.h"


entt::entity Enemy::CreateEnemy(
    const char *spritePath,
    float width,
    float height,
    const Position &position,
    float speed) {
    auto entity = ECSManager::create();
    ECSManager::emplace<EnemyTag>(entity, EnemyTag());
    ECSManager::emplace<Sprite>(entity, spritePath, position, width, height);
    ECSManager::emplace<Position>(entity, position);
    ECSManager::emplace<Speed>(entity, speed);
    ECSManager::emplace<Velocity>(entity, Velocity());
    return entity;
}
