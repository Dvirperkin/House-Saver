#include "House.h"

House::House(const buildingDec & house,
             const buildingsDec & rooms) {
    build(house);

    for (auto it = rooms.first; it < rooms.second; ++it)
        buildRoom({it->cbegin(), it->cend()});
}
//=============================================================================
void House::buildRoom(const buildingDec & room){
    m_rooms.emplace_back(std::make_unique<Room>(room));
}
//=============================================================================