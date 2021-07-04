#pragma once

#include <memory>
#include <vector>
#include <ctime>
#include <sstream>

#include "ContactListener.h"
#include "BuildingDetails.h"
#include "PlayerStats.h"
#include "Factory.h"
#include "Macros.h"
#include "Door.h"

// A class that representing a building inside the game.

class Building {
public:

    //--------------------Constructor/Destructor Section--------------------
    Building(const buildingDec&, const buildingsDec&, PlayerStats &, enum BuildingBackGround_t);

    //--------------------Functions Section--------------------

    // Builds the building object.
    void build(const buildingDec &, const buildingsDec &, PlayerStats &);

    // Runs the building and displays it.
    BuildingDetails runBuilding(sf::RenderWindow& window);

    // Draws the building and all of is objects.
    void draw(sf::RenderWindow& window, const sf::Time & deltaTime);

    // Returns if the mission of the building is complete.
    bool missionComplete() const { return m_details.m_allKeyCollected && m_details.m_killAllEnemy; }

private:

    int m_width; // Building width.
    int m_height; // Building height.
    unsigned int m_keys = 0; // The number of key in the building.
    bool m_inRoom = false; // Indicates if the player is in a room inside the building.

    b2World m_world; // Physical world of the building.
    sf::Sprite m_backGround;
    BuildingDetails m_details;
    ContactListener m_contactListener;

    // Building objects structures.
    std::shared_ptr<Player> m_player;
    std::vector<std::shared_ptr<Enemy>> m_enemies;
    std::vector<std::shared_ptr<Door>> m_doors;
    std::vector<std::shared_ptr<Elevator>> m_elevators;
    std::vector<std::shared_ptr<TakenObject>> m_takenObjects;
    std::vector<std::vector<std::shared_ptr<StaticObject>>> m_staticObjects;

    // Builds a room inside the building.
    std::shared_ptr<Building> buildRoom(PlayerStats &,
                                        const buildingDec &,
                                        const buildingsDec & = buildingsDec());

    // Creates elevator and the connection between 2 other elevators.
    void createElevator(sf::Vector2f);

    // Creates a door and connect it to a room.
    void createDoor(std::vector<building>::const_iterator &,
                    sf::Vector2f,
                    PlayerStats &);

    void createGift(sf::Vector2f);

    // Moves The moving object inside the building
    void moveMovingObject(sf::RenderWindow &);

    // Manages the player actions.
    void action();

    // Changes the view of the camera according the player position.
    void changeView(sf::RenderWindow & window);

    void checkMissionStatus();

    void GameOver(sf::RenderWindow & window);
};
