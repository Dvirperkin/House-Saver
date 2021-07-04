#pragma once

#include "StaticObject.h"

// A class that represents a box object.

class Box : public StaticObject{
public:
    //--------------------Constructor/Destructor Section--------------------
    Box(const sf::Vector2f &, b2World &, const sf::Vector2f&);

    //--------------------Functions Section--------------------
    Objects_t getBodyType() const override {return BOX;}

private:
    static bool m_registerIt;
};