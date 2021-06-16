#pragma once

#include "MovingObject.h"
#include "Player.h"

class Enemy : public MovingObject {
public:

    Enemy(const sf::Vector2f& pos, b2World&);
    virtual AnimationStatus_t move();

    Objects_t getBodyType() const override { return ENEMY; };
    void setDirection(const b2Vec2&);
    b2Vec2 getDirection()const;
    void startContact(Player*);

private:
    b2Vec2 m_dir;
    AnimationStatus_t m_movement = AnimationStatus_t::Idle;
};
