//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"


class Enemy : public Character {

public:
    Enemy(const char* spritePath, float width, float height, const Position& position, float speed);
    ~Enemy() override;
    void initialize() override;
    void update(float dt) override;

private:
    float speed;
    Velocity velocity;

};



#endif //ENEMY_H
