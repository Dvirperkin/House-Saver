#pragma once

#include <sstream>

#include "HousesFile.h"
#include "Screen.h"
#include "Building.h"
#include "PlayerStats.h"

class GamePlay : public Screen {
public:
    GamePlay();
    enum ScreenType_t display(sf::RenderWindow &) override;
    void draw(sf::RenderWindow &) override;

private:

    size_t m_lastHouse;
    sf::Clock m_clock;
    HousesFile m_houseFile;
    PlayerStats m_playerStats;
    std::vector<std::unique_ptr<Building>> m_house;

    void buildHouses();
};