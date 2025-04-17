//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#include "UpdateSpritePositionSystem.h"

#include <iostream>
#include <ostream>

#include "../ECSManager.h"
#include "../../utils/common.h"
#include "../ui/Sprite.h"

void UpdateSpritePositionSystem::update(float dt) {
    for (auto [entity, pos, sprite] : ECSManager::view<Position, Sprite*>().each()) {
        if (sprite) {
            sprite->updatePosition(pos);
        }
    }
}
