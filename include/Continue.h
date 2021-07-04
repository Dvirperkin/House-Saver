#pragma once

#include "Command.h"

// A class that represent a continue command to continue the game.

class Continue : public Command{
public:
    //--------------------Constructor/Destructor Section--------------------
    Continue(const int);

    //--------------------Functions Section--------------------
    bool execute(sf::RenderWindow &) override;
private:
};
