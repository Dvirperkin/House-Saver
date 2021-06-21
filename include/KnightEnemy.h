#pragma once
#include "Enemy.h"

// A class that represents a warrior-type enemy

class KnightEnemy : public Enemy {
public:
    KnightEnemy(const sf::Vector2f &, b2World &, const sf::Vector2f&);

    AnimationStatus_t move();

private:
    static bool m_registerIt;
};