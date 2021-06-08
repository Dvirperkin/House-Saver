#pragma once

#include "StaticObject.h"

class Wall : public StaticObject{
public:
    //----------Constructors\Destructors Section----------
    Wall(const sf::Vector2f & pos, b2World & world)
        : StaticObject(Textures::texturesObject().getSprite(WALL_T), pos, world){};

private:
};