//
// Created by Juan Pablo Hernandez Mosti on 20/04/25.
//

#ifndef SPRITERENDERSYSTEM_H
#define SPRITERENDERSYSTEM_H

#include "../ECSManager.h"
#include "../ui/Sprite.h"

struct SpriteRenderSystem  {
    static void update(float dt) {
        for (auto [entity, sprite] : ECSManager::view<Sprite>().each()) {
            sprite.render();
        }
    }
};

#endif //SPRITERENDERSYSTEM_H
