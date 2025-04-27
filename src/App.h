//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//
#pragma once

#include <memory>
#include "utils/Singleton.h"

class PlayerController;

class App final : public Singleton<App> {
    friend class Singleton<App>;
    App();
public:

    static int run();
    static void exit();

private:
    bool isRunning = false;
    //Init dependencies
    void initialize();
    // Main loop
    void mainLoop();

    void quit();

    // Dependencies
    std::unique_ptr<PlayerController> playerController = nullptr;
};
