#pragma once

#include "Command.h"
#include "Textures.h"
#include "Macros.h"
#include "Menu.h"

// A class that represent a QuitGame command to quit the game.

class QuitGame : public Command{
public:
    //----------Constructors\Destructors Section----------
    QuitGame(const int pos) : Command(pos, "Quit") {}

    //----------Functions Section----------
    bool execute(sf::RenderWindow &) override { exit(EXIT_SUCCESS); };

private:
};
