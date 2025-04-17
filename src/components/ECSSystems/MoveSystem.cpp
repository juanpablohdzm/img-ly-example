//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#include "MoveSystem.h"

#include "../ECSManager.h"
#include "../../utils/common.h"


void MoveSystem::update(float dt) {
    for (auto [entity, pos, vel] : ECSManager::view<Position, Velocity>().each()) {
        pos.x += vel.dx * dt;
        pos.y += vel.dy * dt;
    }
}
