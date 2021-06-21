#include "Door.h"
#include "Building.h"

//=============================================================================
Door::Door(const sf::Vector2f & pos, b2World & world, const sf::Vector2f & dimension,
           std::shared_ptr<Building> building) : m_building(building),
            StaticObject(Textures::texturesObject().getSprite(ELEVATOR_DOOR_T),
                         pos, world, dimension, true, b2_staticBody,
                         std::make_unique<Animation>(Textures::texturesObject().animationData(DOOR_D),
                                                     AnimationStatus_t::Close, getSprite(), dimension)){
    setUserData();
}
//=============================================================================
BuildingDetails Door::runRoom(sf::RenderWindow& window) {
    return m_building->runBuilding(window);
}
//=============================================================================
bool Door::isRoom() const{
    if(m_building)
        return true;
    return false;
}
//=============================================================================
void Door::drawRoom(sf::RenderWindow& window,sf::Time deltaTime) {
    m_building->draw(window, deltaTime);
}
//=============================================================================