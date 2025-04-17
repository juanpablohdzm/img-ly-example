//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#include "Enemy.h"

#include <iostream>

#include <SDL3/SDL_keycode.h>

#include "../ECSManager.h"
#include "../GameManager.h"



Enemy::Enemy(
    const char *spritePath,
    float width,
    float height,
    const Position &position,
    float speed) :
    Character(spritePath,
            width,
            height,
            position),
    speed(speed) {
    ECSManager::emplace<EnemyTag>(getEntity(), EnemyTag());
    ECSManager::emplace<Velocity>(getEntity(), Velocity());
    ECSManager::emplace<Speed>(getEntity(), speed);
}

Enemy::~Enemy() {

}

void Enemy::initialize() {
    ECSManager::emplace<Sprite*>(getEntity(), getSprite());
}

void Enemy::update(float dt) {
}
