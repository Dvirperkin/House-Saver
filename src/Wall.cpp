#include "Wall.h"
#include "Factory.h"

// Registers the Wall object to the objects factory.

bool Wall::m_registerIt = Factory::registerObject('#', [](const sf::Vector2f &pos,
                                                            b2World &world) -> std::shared_ptr<GameObject> {
    return std::make_shared<Wall>(pos, world);
});
//=============================================================================
Wall::Wall(const sf::Vector2f &pos, b2World &world) :
            StaticObject(Textures::texturesObject().getSprite(WALL_T), pos, world, false, b2_staticBody){
}
//=============================================================================