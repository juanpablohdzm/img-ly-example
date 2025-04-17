//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#include "Character.h"

#include "../ECSManager.h"
#include "../ui/Sprite.h"

Character::Character(const char* path, float width, float height, const Position& position) {
    sprite = std::make_unique<Sprite>(
        path,
        position,
        width,
        height
    );
    entity = ECSManager::create();
    ECSManager::emplace<Position>(entity, position);

}

Character::~Character() {
}
