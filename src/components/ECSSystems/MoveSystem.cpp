//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#include "MoveSystem.h"

#include "../ECSManager.h"
#include "../../utils/common.h"


void MoveSystem::update(float dt) {
    for (auto [entity, pos, vel, speed] : ECSManager::view<Position, Velocity, Speed>().each()) {
        pos.x += vel.dx * dt * speed.value;
        pos.y += vel.dy * dt * speed.value;
    }
}
