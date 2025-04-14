//
// Created by Juan Pablo Hernandez Mosti on 14/04/25.
//

#ifndef GAMEHUD_H
#define GAMEHUD_H
#include "../Canvas.h"


class GameHud : public Canvas{

public:
    GameHud(PlayerController* playerController);

    void initialize() override;

};



#endif //GAMEHUD_H
