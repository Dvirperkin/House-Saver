#pragma once

#include "StaticObject.h"

// An abstract class that represents a static object.

class TakenObject : public StaticObject{
public:
    //----------Constructors\Destructors Section----------
    TakenObject(const sf::Sprite &sprite , const sf::Vector2f &pos, b2World & world, const sf::Vector2f &,const bool, b2BodyType,
                std::unique_ptr<Animation> animation);

    //----------Functions Section----------
    bool isTaken() const { return m_taken; }
    void take() { m_taken = true; }

private:
    bool m_taken = false;
};