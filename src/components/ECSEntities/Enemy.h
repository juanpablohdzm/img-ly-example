//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#ifndef ENEMY_H
#define ENEMY_H

#include <entt/entity/entity.hpp>
#include "../ECSComponents/ECSComponentsGeneral.h"

class Enemy {

public:
    static entt::entity CreateEnemy(const char* spritePath, float width, float height, const Position& position, float speed);
};



#endif //ENEMY_H
