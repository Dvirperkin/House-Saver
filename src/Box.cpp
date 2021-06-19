#include "Box.h"
#include "Factory.h"

// Registers the Box object to the objects factory.

bool Box::m_registerIt = Factory::registerObject('B', [](const sf::Vector2f &pos,
                                                         b2World &world) -> std::shared_ptr<GameObject> {
    return std::make_shared<Box>(pos, world);
});
//=============================================================================
Box::Box(const sf::Vector2f & pos, b2World & world) : StaticObject(Textures::texturesObject().getSprite(BOX_T),
                                                                   pos, world, false, b2_dynamicBody){
    setFixedRotation(true);
}
//=============================================================================