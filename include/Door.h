#pragma once

#include "StaticObject.h"

class Building;
class BuildingDetails;

// A class that represent a door to building.

class Door : public StaticObject{
public:
    //--------------------Constructor/Destructor Section--------------------
    Door(const sf::Vector2f &, b2World &, const sf::Vector2f &,
         std::shared_ptr<Building> = nullptr);

    //--------------------Functions Section--------------------
    BuildingDetails runRoom(sf::RenderWindow&);

    void open() {setAnimationStatus( AnimationStatus_t::Open); }
    void close() {setAnimationStatus( AnimationStatus_t::Close); }
    void drawRoom(sf::RenderWindow& window, sf::Time deltaTime);

    Objects_t getBodyType() const override {return DOOR;}

    // Indicates if the door leads to a building.
    bool isRoom() const;

    bool isRoomMissionComplete() const;

private:
    static bool m_registerIt;
    std::shared_ptr<Building> m_building = nullptr;
};