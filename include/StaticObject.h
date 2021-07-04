#pragma once

#include "GameObject.h"
#include "Factory.h"

// An abstract class that represents a static object.

class StaticObject : public GameObject{
public:
    //----------Constructors\Destructors Section----------
    StaticObject(const sf::Sprite &, const sf::Vector2f &, b2World &, const sf::Vector2f&, const bool , b2BodyType,
                 std::unique_ptr<Animation> = nullptr);
private:
};