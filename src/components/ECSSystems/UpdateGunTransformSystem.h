//
// Created by Juan Pablo Hernandez Mosti on 22/04/25.
//

#ifndef UPDATEGUNTRANSFORMSYSTEM_H
#define UPDATEGUNTRANSFORMSYSTEM_H
#include "../ECSManager.h"
#include "../PlayerController.h"
#include "../ECSComponents/GunTag.h"
#include "../ECSComponents/PositionComp.h"
#include "../ECSComponents/PlayerTag.h"
#include "../ui/Sprite.h"

struct UpdateGunTransformSystem {
    static void update(float dt) {

        Position playerPos {0, 0};
        float playerWidth = 0.0f;
        float playerHeight = 0.0f;
        for (auto [entity, pos, sprite] : ECSManager::view<Position, Sprite, PlayerTag>().each()) {
            playerPos = pos;
            playerWidth = sprite.getWidth();
            playerHeight = sprite.getHeight();
        }

        const auto [mouseX, mouseY] = PlayerController::getMousePosition();

        constexpr float radiusOffset = 70.0f;
        for (auto [entity, pos] : ECSManager::view<Position, GunTag>().each()) {
            const float angle =  std::atan2f(mouseY - playerPos.y, mouseX - playerPos.x);

            pos.x = playerPos.x + playerWidth * 0.25f + cos(angle) * radiusOffset;
            pos.y = playerPos.y + playerHeight * 0.25f + sin(angle) * radiusOffset;
        }
    }
};

#endif //UPDATEGUNTRANSFORMSYSTEM_H
