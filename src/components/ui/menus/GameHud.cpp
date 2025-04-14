//
// Created by Juan Pablo Hernandez Mosti on 14/04/25.
//

#include "GameHud.h"

GameHud::GameHud(PlayerController *playerController) : Canvas(playerController) {
}

void GameHud::initialize() {
    Canvas::initialize();
}
