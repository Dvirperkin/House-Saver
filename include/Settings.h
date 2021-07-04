#pragma once

#include "Command.h"
#include "Menu.h"
#include "SFX.h"
#include "Audio.h"
#include "Exit.h"

// A class that represent a Settings command that implement a sub menu of game settings.

class Settings : public Command {
public:
    //----------Constructors\Destructors Section----------
	Settings(const int);

    //----------Functions Section----------
	bool execute(sf::RenderWindow &)override;

private:
    Menu m_settings;
    bool m_return;
};