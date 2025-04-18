//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#ifndef ENEMYVELOCITYSYSTEM_H
#define ENEMYVELOCITYSYSTEM_H

#include "../ECSManager.h"
#include "../ECSComponents/ECSComponentsGeneral.h"

struct EnemyVelocitySystem {
    static void update(float dt) {

        Position playerPos {0, 0};
        for (auto [entity, pos] : ECSManager::view<Position, PlayerTag>().each()) {
            playerPos = pos;
        }

        for (auto [entity, pos, vel] : ECSManager::view<Position, Velocity, EnemyTag>().each()) {

            if (pos.x < playerPos.x) {
                vel.dx = 1;
            } else if (pos.x > playerPos.x) {
                vel.dx = -1;
            } else {
                vel.dx = 0;
            }

            if (pos.y < playerPos.y) {
                vel.dy = 1;
            } else if (pos.y > playerPos.y) {
                vel.dy = -1;
            } else {
                vel.dy = 0;
            }

            float magnitude = std::sqrt(vel.dx * vel.dx + vel.dy * vel.dy);
            if (magnitude > 0) {
                vel.dx /= magnitude;
                vel.dy /= magnitude;
            }
        }
    }
};



#endif //ENEMYVELOCITYSYSTEM_H
