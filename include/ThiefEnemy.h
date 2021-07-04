#pragma once

#include "Enemy.h"

// A class that represents a thief enemy

class ThiefEnemy : public Enemy {
public:
    //----------Constructors\Destructors Section----------
    ThiefEnemy(const sf::Vector2f &, b2World &, const sf::Vector2f&);

    //----------Functions Section----------
    AnimationStatus_t move(sf::Vector2f);

    Objects_t getBodyType() const override { return THIEF_ENEMY; }

private:
    static bool m_registerIt;
};