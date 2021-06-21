#pragma once

#include <memory>
#include <vector>
#include <sstream>

#include "ContactListener.h"
#include "BuildingDetails.h"
#include "PlayerStats.h"
#include "Macros.h"
#include "Factory.h"
#include "Door.h"


class Building {
public:
    Building(const buildingDec&, const buildingsDec&, PlayerStats &);

    void build(const buildingDec &, const buildingsDec &, PlayerStats &);

    BuildingDetails runBuilding(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window, const sf::Time & deltaTime);

private:
    int m_width;
    int m_height;
    b2World m_world;
    bool m_inRoom = false;
    BuildingDetails m_details;
    ContactListener m_contactListener;

    std::shared_ptr<Player> m_player;
    std::vector<std::shared_ptr<Enemy>> m_enemy;
    std::vector<std::shared_ptr<Door>> m_doors;
    std::vector<std::shared_ptr<Elevator>> m_elevators;
    std::vector<std::shared_ptr<TakenObject>> m_takenObjects;
    std::vector<std::vector<std::shared_ptr<StaticObject>>> m_staticObjects;

    std::shared_ptr<Building> buildRoom(PlayerStats &,
                                        const buildingDec &,
                                        const buildingsDec & = buildingsDec());
    void createElevator(sf::Vector2f);
    void createDoor(std::vector<building>::const_iterator &,
                    sf::Vector2f,
                    PlayerStats &);

    void moveMovingObject();
    void action();
    void changeView(sf::RenderWindow & window);
};
