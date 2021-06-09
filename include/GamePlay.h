#pragma once

#include <sstream>

#include "HousesFile.h"
#include "Screen.h"
#include "House.h"

class GamePlay : public Screen {
public:
    GamePlay();
    enum ScreenType_t display(sf::RenderWindow &) override;
    void draw(sf::RenderWindow &) override;

private:
    size_t m_lastHouse;
    sf::Clock m_clock;
    HousesFile m_houseFile;
    std::vector<std::unique_ptr<House>> m_house;

    void buildHouses();
};