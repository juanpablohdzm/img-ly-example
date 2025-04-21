//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#ifndef ENEMYVELOCITYSYSTEM_H
#define ENEMYVELOCITYSYSTEM_H

#include "../ECSManager.h"
#include "../ECSComponents/ECSComponentsGeneral.h"

struct UpdateEnemyTargetSystem {
    static void update(float dt) {

        Position playerPos {0, 0};
        for (auto [entity, pos] : ECSManager::view<Position, PlayerTag>().each()) {
            playerPos = pos;
        }

        for (auto [entity, target] : ECSManager::view<TargetPosition>().each()) {
            target.x = playerPos.x;
            target.y = playerPos.y;
        }
    }
};



#endif //ENEMYVELOCITYSYSTEM_H
