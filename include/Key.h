#pragma once

#include "TakenObject.h"

class Key : public TakenObject {
public:
    //----------Constructors\Destructors Section----------
    Key(const sf::Vector2f& , b2World&);
    Objects_t getBodyType() const override {return KEY;}

private:
};