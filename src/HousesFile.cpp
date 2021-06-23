#include "HousesFile.h"

HousesFile::HousesFile(const std::string & fileName) : m_currHouse(0) {
    auto houseFile = std::fstream(fileName);

    if(!houseFile)
        throw std::runtime_error("HousesFile.txt is missing.");

    int numOfHouses;

    if(!(houseFile >> numOfHouses))
        throw std::invalid_argument("Number of houses must be positive number.");
    houseFile.get();

    m_houses.resize(numOfHouses);
    m_rooms.resize(numOfHouses);

    for(auto i = 0; i < numOfHouses; ++i, ++m_currHouse)
        readBuilding(houseFile, Building_t::HOUSE);

    m_currHouse = 0;
}
//=============================================================================
void HousesFile::readBuilding(std::fstream & houseFile, enum Building_t building, int buildingNum) {

    int buildingWidth, buildingHeight, numOfRooms;
    auto stringStream = std::stringstream();
    auto line = std::string();

    // Reads the dimension of the building.
    std::getline(houseFile,line);
    stringStream << line;

    if(!(stringStream >> buildingWidth >> buildingHeight)){
        throw std::invalid_argument("Building width and height must be a positive number.");
    }

    // Reads number of rooms if the current building is an house.
    if(building == Building_t::HOUSE) {
        if (!(stringStream >> numOfRooms)) {
            throw std::invalid_argument("");
        }
        m_rooms[m_currHouse].resize(numOfRooms);
        m_houses[m_currHouse].emplace_back(line);
    }

    else
        m_rooms[m_currHouse][buildingNum].emplace_back(line);

    // Reads building declaration.
    for(auto i = 0; i < buildingHeight; ++i){
        std::getline(houseFile,line);

        if(building == Building_t::HOUSE)
            m_houses[m_currHouse].emplace_back(line);
        else
            m_rooms[m_currHouse][buildingNum].emplace_back(line);
    }

    // Reads the rooms of the house.
    if(building == Building_t::HOUSE) {
        for (auto i = 0; i < numOfRooms; ++i)
            readBuilding(houseFile, Building_t::ROOM, i);
    }
}
//=============================================================================
bool HousesFile::eof() const {
    return m_currHouse == m_houses.size();
}
//=============================================================================
std::pair<buildingDec, buildingsDec> HousesFile::getHouse(){

    // This function return pair of iterators to the vector of the current house
    // and iterators to the vector of the rooms of the current house.

    auto beginHouse = m_houses[m_currHouse].cbegin();
    auto endHouse = m_houses[m_currHouse].cend();

    auto beginRooms = m_rooms[m_currHouse].cbegin();
    auto endRooms = m_rooms[m_currHouse].cend();

    ++m_currHouse;

    auto house = std::make_pair(std::make_pair(beginHouse, endHouse),
                                std::make_pair(beginRooms, endRooms));

    return house;
}
//=============================================================================


