//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#ifndef MAINMENU_H
#define MAINMENU_H
#include <memory>

#include "../Canvas.h"

class Button;
class Sprite;
class GameManager;

class MainMenu : public Canvas {
public:
    MainMenu(PlayerController* playerController);
    ~MainMenu() override;

    void initialize() override;

private:
    std::unique_ptr<Button> playButton = nullptr;
    std::unique_ptr<Button> quitButton = nullptr;
    std::unique_ptr<Sprite> banner = nullptr;
};



#endif //MAINMENU_H
