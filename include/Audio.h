#pragma once

#include "Command.h"
#include "Sounds.h"

// A class that implements a command in the menu that handles the in-game audio mute.

class Audio : public Command {
public:
    //--------------------Constructor/Destructor Section--------------------
	Audio(const int);

    //--------------------Functions Section--------------------
	bool execute(sf::RenderWindow&) override;

};