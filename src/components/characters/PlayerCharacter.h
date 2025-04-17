//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include "Character.h"


class PlayerCharacter : public Character {

public:
    PlayerCharacter(const char* spritePath, float width, float height, const Position& position, float speed, PlayerController* controller);
    ~PlayerCharacter() override;
    void update(float dt) override;
    void initialize() override;

private:
    float speed;
    Velocity velocity;

};



#endif //PLAYERCHARACTER_H
