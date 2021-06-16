#pragma once

#include "MovingObject.h"
#include "Key.h"

class Player : public MovingObject {
public:

    Player(const sf::Vector2f& pos, b2World&);
    AnimationStatus_t move();

    Objects_t getBodyType() const override {return PLAYER;};

    void startContact(Key *);

private:
    unsigned int m_keys = 0;
    AnimationStatus_t m_movement = AnimationStatus_t::Idle;
};
