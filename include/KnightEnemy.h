#pragma once
#include "Enemy.h"

// A class that represents a warrior-type enemy

class KnightEnemy : public Enemy {
public:
    KnightEnemy(const sf::Vector2f &, b2World &);

    AnimationStatus_t move();

private:
    static bool m_registerIt;
};