#pragma once

#include <sstream>

#include "HousesFile.h"
#include "Macros.h"
#include "Screen.h"
#include "House.h"

class GamePlay : public Screen {
public:
    GamePlay();
    enum ScreenType_t display(sf::RenderWindow &) override;
    void draw(sf::RenderWindow &) override;

private:
    int m_lastHouse;
    HousesFile m_houseFile;
    std::vector<std::unique_ptr<House>> m_house;

    void buildHouses();
};