#include "Box.h"

// Registers the Box object to the static Objects factory.

bool Box::m_registerIt = Factory<StaticObject>::registerObject(BOX, [](const sf::Vector2f &pos,
                                                         b2World &world, const sf::Vector2f& dimension) -> std::shared_ptr<StaticObject> {
    return std::make_shared<Box>(pos, world, dimension);
});
//=============================================================================
Box::Box(const sf::Vector2f & pos, b2World & world, const sf::Vector2f& dimension) : StaticObject(Textures::texturesObject().getSprite(BOX_T),
                                                                   pos, world, dimension, false, b2_dynamicBody){
    setFixedRotation(true);
    setUserData();
}
//=============================================================================