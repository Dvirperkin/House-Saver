#pragma once

#include "StaticObject.h"

class Box : public StaticObject{
public:
    Box(const sf::Vector2f &, b2World &);

    Objects_t getBodyType() const override {return BOX;}
private:
};