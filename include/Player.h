#pragma once

#include "MovingObject.h"

class Player : public MovingObject {
public:

    Player(const sf::Vector2f& pos, b2World&);
    AnimationStatus_t move();

private:
};
