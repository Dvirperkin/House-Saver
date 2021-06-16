#pragma once

#include "MovingObject.h"

class Bullet : public MovingObject{
public:
    Bullet(const sf::Vector2f&, b2World &);

private:

};