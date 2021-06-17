#pragma once

#include "Building.h"
#include "Room.h"

// A class that represents an house.

class House : public Building{
public:
    House(const buildingDec &, const buildingsDec &);

    void buildRoom(const buildingDec &);
private:
    std::vector<std::unique_ptr<Room>> m_rooms;
};