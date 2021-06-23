#pragma once

#include "MovingObject.h"

#include <iostream>

class Enemy;
class Bullet : public MovingObject{
public:
    Bullet(const sf::Vector2f &, b2World &, const sf::Vector2f &, const Side_t &, const float &, const float &,const int);
    Objects_t getBodyType()const override { return BULLET; }
    bool shoot();
    void hit() { m_disposed = true; }
    float getHit() const { return m_hitPoint;}

private:
    bool m_disposed = false;
    float m_hitPoint;
    float m_desiredVel = 5;
    Side_t m_sideToShoot;
    sf::Clock m_clock;
};