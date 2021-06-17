#pragma once

#include <memory>
#include <vector>
#include <sstream>

#include "Macros.h"
#include "Factory.h"
#include "ContactListener.h"

class Building {
public:
    Building();

    void build(const buildingDec &);

    void runBuilding(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window, const sf::Time & deltaTime);

protected:
    b2World m_world;

private:
    ContactListener m_contactListener;
    std::unique_ptr<Player> m_player;
    std::vector<std::unique_ptr<Enemy>> m_enemy;
    std::vector<std::unique_ptr<TakenObject>> m_takenObjects;
    std::vector<std::vector<std::unique_ptr<StaticObject>>> m_staticObjects;

    void moveMovingObject();
    void changeView(sf::RenderWindow & window);
};
