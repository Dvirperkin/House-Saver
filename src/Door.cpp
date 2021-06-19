#include "Door.h"
// Registers the Box object to the objects factory.

bool Door::m_registerIt = Factory::registerObject('D', [](const sf::Vector2f &pos,
                                                              b2World &world) -> std::shared_ptr<GameObject> {
    return std::make_shared<Door>(pos, world);
});
//=============================================================================
Door::Door(const sf::Vector2f & pos, b2World & world) :
            StaticObject(Textures::texturesObject().getSprite(ELEVATOR_DOOR_T),
                         pos, world, true, b2_staticBody,
                         std::make_unique<Animation>(Textures::texturesObject().animationData(DOOR_D),
                                                     AnimationStatus_t::Close, getSprite())){
    setUserData();
}
//=============================================================================
void Door::setRoom(Room & room) {
    m_room = &room;
}
//=============================================================================