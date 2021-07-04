#pragma once

#include <sstream>

#include "Command.h"
#include "Menu.h"
#include "Continue.h"
#include "Settings.h"
#include "HowToPlay.h"
#include "Exit.h"
#include "Building.h"
#include "HousesFile.h"
#include "PlayerStats.h"

// A class that represent a GamePlay command in the menu that start the game.
// The GamePlay class is the Game Controller of the game.

class GamePlay : public Command {
public:
    //--------------------Constructor/Destructor Section--------------------
    GamePlay(int);

    //--------------------Functions Section--------------------
    bool execute(sf::RenderWindow &) override;

private:

    Menu m_pause;
    int m_currHouse;
    bool m_returnMainMenu; // Indicates that the user wants to return to the main menu.

    sf::Clock m_clock;
    HousesFile m_houseFile;
    PlayerStats m_playerStats;
    std::vector<std::unique_ptr<Building>> m_house;

    void buildHouses();
    void draw(sf::RenderWindow &);
    void GameComplete(sf::RenderWindow &);
    void GameOver(sf::RenderWindow &);
    void LevelUp(sf::RenderWindow &);
    void restartGame(sf::RenderWindow &);
    void displayScreen(sf::RenderWindow &, Textures_t);
    void pauseMenu(sf::RenderWindow &);
};