#pragma once

#include "Building.h"
#include "Room.h"

// A class that represents an house.

class House : public Building{
public:
    House(const buildingDec &, const buildingsDec &);

    void buildRoom(const buildingDec &);

    void runBuilding(sf::RenderWindow& window);

    bool isInRoom() const {return m_inRoom;}

private:

    bool m_inRoom = false;

    std::vector<std::unique_ptr<Room>> m_rooms;
};