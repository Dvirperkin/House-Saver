#pragma once

#include "Command.h"

// A class that represent a exit command to exit from the menu.

class Exit : public Command {
public:
    //--------------------Constructor/Destructor Section--------------------
	Exit(const int, bool &);

    //--------------------Functions Section--------------------
	bool execute(sf::RenderWindow &) override;

private:
    bool & m_return;
};