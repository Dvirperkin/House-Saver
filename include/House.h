#pragma once

#include <memory>
#include "StaticObject.h"
#include "Macros.h"
#include "Wall.h"
#include "Player.h"

using constIterToVecStr = std::vector<std::string>::const_iterator;

class House {
public:
    House(const constIterToVecStr &,
          const constIterToVecStr &);

    void runHouse(sf::RenderWindow &);

    void draw(sf::RenderWindow &);
private:
    b2World m_world;
    std::unique_ptr<Player> m_player;
    std::vector<std::vector<std::unique_ptr<StaticObject>>> m_staticObjects;


    void buildHouse(const constIterToVecStr &,
                    const constIterToVecStr &);
};