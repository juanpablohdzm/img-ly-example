//
// Created by Juan Pablo Hernandez Mosti on 21/04/25.
//

#ifndef UPDATEENEMYVELOCITYSYSTEM_H
#define UPDATEENEMYVELOCITYSYSTEM_H
#include "../ECSManager.h"
#include "../ECSComponents/ECSComponentsGeneral.h"

struct UpdateEnemyVelocitySystem {
    static void update(float dt) {
        for (auto [entity, vel, pos, targetPos] : ECSManager::view<Velocity, Position, TargetPosition>().each()) {
            vel.dx = targetPos.x - pos.x;
            vel.dy = targetPos.y - pos.y;
        }
    }
};

#endif //UPDATEENEMYVELOCITYSYSTEM_H
