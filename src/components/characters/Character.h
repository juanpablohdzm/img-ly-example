//
// Created by Juan Pablo Hernandez Mosti on 17/04/25.
//

#ifndef CHARACTER_H
#define CHARACTER_H
#include <memory>
#include <entt/entt.hpp>

#include "../../utils/common.h"

class PlayerController;
class Sprite;

class Character {
public:
    Character(const char* spritePath, int width, int height, const Position& position = {0, 0});

    virtual ~Character();
    virtual void initialize() = 0;
    virtual void update(float dt) = 0;

    [[nodiscard]] bool isControlled() const { return controller != nullptr; }
    [[nodiscard]] PlayerController* getController() const { return controller; }
    void setController(PlayerController* controller) { this->controller = controller; }

    [[nodiscard]] Sprite* getSprite() const { return sprite.get(); }
    [[nodiscard]] entt::entity getEntity() const { return entity; }

private:
    std::unique_ptr<Sprite> sprite;
    PlayerController* controller{};
    entt::entity entity;
};

#endif //CHARACTER_H
