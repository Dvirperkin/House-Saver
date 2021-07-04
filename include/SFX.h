#pragma once

#include "Command.h"
#include "Sounds.h"

// This class implements a command in the menu that handles the in-game SFX mute.

class SFX : public Command {
public:
    //----------Constructors\Destructors Section----------
	SFX(const int);

    //----------Functions Section----------
	bool execute(sf::RenderWindow&) override;

private:
};