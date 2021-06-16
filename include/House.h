#pragma once

#include <memory>
#include <vector>

#include "ContactListener.h"
#include "Macros.h"
#include "Player.h"
#include "Wall.h"
#include "Box.h"
#include "Key.h"

#include "Enemy.h"
#include "KnightEnemy.h"

using constIterToVecStr = std::vector<std::string>::const_iterator;

class House {
public:
    House(const constIterToVecStr &,
          const constIterToVecStr &);

    void runHouse(sf::RenderWindow &);
    void changeView(sf::RenderWindow &);
    void draw(sf::RenderWindow &, const sf::Time &);
private:
    
    b2World m_world;
    std::unique_ptr<Player> m_player;
    std::vector<std::unique_ptr<Enemy>> m_enemy;
    ContactListener m_contactListener;
    std::vector<std::unique_ptr<TakenObject>> m_takenObjects;
    std::vector<std::vector<std::unique_ptr<StaticObject>>> m_staticObjects;

    void buildHouse(const constIterToVecStr &,
                    const constIterToVecStr &);
};