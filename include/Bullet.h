#pragma once

#include "MovingObject.h"

// A class that represent a bullet.

class Bullet : public MovingObject{
public:
    //--------------------Constructor/Destructor Section--------------------
    Bullet(const sf::Vector2f &, b2World &, const sf::Vector2f &, const Side_t &,
           const float &, const float &,const int);

    //--------------------Functions Section--------------------
    Objects_t getBodyType()const override { return BULLET; }
    float getHit() const { return m_hitPoint;}
    void hit() { m_disposed = true; }
    bool shoot();

private:
    sf::Clock m_clock;
    bool m_disposed = false;
    float m_hitPoint;
    float m_desiredVel;
    Side_t m_sideToShoot;
};