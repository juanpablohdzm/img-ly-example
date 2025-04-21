//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include <entt/entity/entity.hpp>
#include "../ECSComponents/ECSComponentsGeneral.h"


class PlayerController;

class PlayerCharacter {

public:
    PlayerCharacter(const char* spritePath, float width, float height, const Position& position, float speed, PlayerController* controller);
    ~PlayerCharacter();

private:
    PlayerController* controller = nullptr;
};



#endif //PLAYERCHARACTER_H
