#include "Box.h"

Box::Box(const sf::Vector2f & pos, b2World & world) : StaticObject(Textures::texturesObject().getSprite(BOX_T),
                                                                   pos, world, false, b2_dynamicBody){
    setFixedRotation(true);
}
