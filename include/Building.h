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

// A class that representing a building inside the game

class Building {
public:
    //Constructor
    Building(const buildingDec&, const buildingsDec&, PlayerStats &);

    void build(const buildingDec &, const buildingsDec &, PlayerStats &); //Build the building objects

    BuildingDetails runBuilding(sf::RenderWindow& window); //Runs the building

    void draw(sf::RenderWindow& window, const sf::Time & deltaTime); //Draw all the objects inside the building

    bool missionComplete() const { return m_details.m_missionComplete; }

private:
    unsigned int m_keys = 0;
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
                                        const buildingsDec & = buildingsDec()); // Creates a room inside the building
    
    void createElevator(sf::Vector2f); // Creates the connection between 2 elevators
    void createDoor(std::vector<building>::const_iterator &,
                    sf::Vector2f,
                    PlayerStats &); // Creates a room for door
    void createGift(sf::Vector2f);
    void moveMovingObject(sf::RenderWindow &); // Moves The moving object inside the building
    void action(); // Manage the player actions
    void changeView(sf::RenderWindow & window); // Change the view of the camera
    void checkMissionStatus();
    void GameOver(sf::RenderWindow & window);
};
