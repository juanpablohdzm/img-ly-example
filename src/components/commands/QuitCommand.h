//
// Created by Juan Pablo Hernandez Mosti on 09/04/25.
//

#ifndef QUITCOMMAND_H
#define QUITCOMMAND_H
#include "Command.h"


class App;

class QuitCommand : public Command {
public:
    explicit QuitCommand(App& app);
    void execute() const override;

private:
    App* app;
};



#endif //QUITCOMMAND_H
