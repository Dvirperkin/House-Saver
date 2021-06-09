#pragma once

#include "MovingObject.h"
#include "Animation.h"
#include "Direction.h"

class Player : public MovingObject {
public:

    Player(const sf::Vector2f& pos, b2World&);
    void move();
    void update(sf::Time);

private:
    Animation m_animation;
    Direction m_movement = Direction::Idle;
};
