#pragma once

#include "GameObject.h"

class MovingObject : public GameObject {
public:
    MovingObject(const sf::Sprite& sprite, const sf::Vector2f& pos, b2World&);
    virtual void move(float, float);
private:

};
