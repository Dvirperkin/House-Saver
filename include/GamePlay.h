#pragma once

#include <sstream>

#include "HousesFile.h"
#include "Command.h"
#include "Building.h"
#include "PlayerStats.h"

class GamePlay : public Command {
public:
    GamePlay(int);
    bool execut(sf::RenderWindow &) override;


private:

    int m_currHouse;
    sf::Clock m_clock;
    HousesFile m_houseFile;
    PlayerStats m_playerStats;
    std::vector<std::unique_ptr<Building>> m_house;

    void buildHouses();
    void draw(sf::RenderWindow &);
    void GameComplete(sf::RenderWindow &);
    void GameOver(sf::RenderWindow &);
    void restartGame();
    void pauseMenu(sf::RenderWindow &);
};