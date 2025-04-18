//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#ifndef MOVESYSTEM_H
#define MOVESYSTEM_H

#include "../ECSManager.h"
#include "../ECSComponents/ECSComponentsGeneral.h"

struct MoveSystem {
    static void update(float dt) {
        for (auto [entity, pos, vel, speed] : ECSManager::view<Position, Velocity, Speed>().each()) {
            pos.x += vel.dx * dt * speed.value;
            pos.y += vel.dy * dt * speed.value;
        }
    }
};



#endif //MOVESYSTEM_H
