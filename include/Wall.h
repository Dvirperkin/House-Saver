#pragma once

#include "StaticObject.h"

// A class that represents a wall object.

class Wall : public StaticObject{
public:
    //----------Constructors\Destructors Section----------
    Wall(const sf::Vector2f & pos, b2World & world, const sf::Vector2f&);

    //----------Functions Section----------
    Objects_t getBodyType() const override { return WALL; }

private:
    static bool m_registerIt;
};