//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#ifndef UPDATESPRITEPOSITIONSYSTEM_H
#define UPDATESPRITEPOSITIONSYSTEM_H

#include "../ECSManager.h"
#include "../ECSComponents/ECSComponentsGeneral.h"
#include "../ui/Sprite.h"

struct  UpdateSpritePositionSystem {
    static void update(float dt) {
        for (auto [entity, pos, sprite] : ECSManager::view<Position, Sprite*>().each()) {
            if (sprite) {
                sprite->updatePosition(pos);
            }
        }
    }
};



#endif //UPDATESPRITEPOSITIONSYSTEM_H
