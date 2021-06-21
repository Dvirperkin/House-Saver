#pragma once
#include "Enemy.h"

// A class that represents a warrior-type enemy

class KnightEnemy : public Enemy {
public:
    KnightEnemy(const sf::Vector2f &, b2World &, const sf::Vector2f&);

    AnimationStatus_t move(sf::Vector2f);

    Objects_t getBodyType() const override { return KNIGHT_ENEMY; }

private:
    static bool m_registerIt;
};