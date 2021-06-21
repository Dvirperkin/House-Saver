#include "Elevator.h"
#include "Factory.h"

//=============================================================================
Elevator::Elevator(const sf::Vector2f & pos, b2World & world, const sf::Vector2f& dimension) :
        StaticObject(Textures::texturesObject().getSprite(ELEVATOR_DOOR_T),
                     pos, world, dimension, true, b2_staticBody,
                     std::make_unique<Animation>(Textures::texturesObject().animationData(ELEVATOR_D),
                                                 AnimationStatus_t::Close, getSprite(), dimension)){
    setUserData();
}
//=============================================================================
b2Vec2 Elevator::getElevatorDestinationUp() const{
    if (m_destinationUP)
        return m_destinationUP->getBodyPos();
}
//=============================================================================
b2Vec2 Elevator::getElevatorDestinationDown() const {
    if (m_destinationDown)
        return m_destinationDown->getBodyPos();
}
//=============================================================================