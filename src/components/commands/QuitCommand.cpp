//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//

#include "QuitCommand.h"

#include "../../App.h"

QuitCommand::QuitCommand(App& app) : app(&app) {
}

void QuitCommand::execute() const {
    app->quit();
}
