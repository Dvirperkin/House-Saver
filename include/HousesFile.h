#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "Macros.h"

// A class that represents a read-only file that manages all readings
// from the houses file according to the required protocol.

class HousesFile {
public:
    HousesFile(const std::string &);
    std::pair<buildingDec, buildingsDec> getHouse();
    bool eof() const;

private:

    int m_currHouse;
    std::vector<building> m_houses;
    std::vector<std::vector<building>> m_rooms;

    void readBuilding(std::fstream &, enum Building_t, int = 0);
};