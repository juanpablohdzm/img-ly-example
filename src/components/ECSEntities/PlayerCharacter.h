//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#pragma once

class PlayerController;
struct Position;

class PlayerCharacter {

public:
    PlayerCharacter(const char* spritePath, float width, float height, const Position& position, float speed, PlayerController* controller);
    ~PlayerCharacter();

private:
    PlayerController* controller = nullptr;
};
