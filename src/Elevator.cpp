#include "Elevator.h"
#include "Factory.h"

// Registers the Box object to the objects factory.

bool Elevator::m_registerIt = Factory::registerObject('^', [](const sf::Vector2f &pos,
                                                         b2World &world) -> std::shared_ptr<GameObject> {
    return std::make_shared<Elevator>(pos, world);
});
//=============================================================================
Elevator::Elevator(const sf::Vector2f & pos, b2World & world) :
        StaticObject(Textures::texturesObject().getSprite(ELEVATOR_DOOR_T),
                     pos, world, true, b2_staticBody,
                     std::make_unique<Animation>(Textures::texturesObject().animationData(ELEVATOR_D),
                                                 AnimationStatus_t::Close, getSprite())){
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