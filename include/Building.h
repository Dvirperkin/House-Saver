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


private:
    int m_height;
    int m_width;
    b2World m_world;
    ContactListener m_contactListener;
    std::shared_ptr<Player> m_player;
    std::vector<std::shared_ptr<Enemy>> m_enemy;
    std::vector<std::shared_ptr<Elevator>> m_elevators;
    std::vector<std::shared_ptr<TakenObject>> m_takenObjects;
    std::vector<std::vector<std::shared_ptr<StaticObject>>> m_staticObjects;

    void createElevator(sf::Vector2f);
    void moveMovingObject();
    void changeView(sf::RenderWindow & window);
};
