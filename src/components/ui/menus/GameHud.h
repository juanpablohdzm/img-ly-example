//
// Created by Juan Pablo Hernandez Mosti on 14/04/25.
//

#ifndef GAMEHUD_H
#define GAMEHUD_H
#include "../Canvas.h"

class Widget;

class GameHud : public Canvas{

public:
    GameHud(PlayerController* playerController);
    ~GameHud() override;

    void initialize() override;
    void update(float deltaTime) override;

private:
    std::unique_ptr<Widget> scoreLabel;
    std::unique_ptr<Widget> scoreValue;

};



#endif //GAMEHUD_H
