#pragma once

#include "GameObject.h"

class StaticObject : public GameObject{
public:
    //----------Constructors\Destructors Section----------
    StaticObject(const sf::Sprite & sprite, const sf::Vector2f & pos, b2World &,
                 std::unique_ptr<Animation> = nullptr);
private:
    b2BodyDef m_bodyDef;
};