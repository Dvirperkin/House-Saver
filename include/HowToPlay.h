#pragma once

#include "Command.h"

// A class that represent a HowToPlay command to display the game instructions.

class HowToPlay : public Command {
public:
    //----------Constructors\Destructors Section----------
	HowToPlay(const int);

    //----------Functions Section----------
	bool execute(sf::RenderWindow&) override;

private:
};
