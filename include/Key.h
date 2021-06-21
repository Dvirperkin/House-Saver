#pragma once

#include "TakenObject.h"

//A class that represents a key object.

class Key : public TakenObject {
public:
    //----------Constructors\Destructors Section----------
    Key(const sf::Vector2f& , b2World&, const sf::Vector2f &);
    Objects_t getBodyType() const override {return KEY;}

private:
    static bool m_registerIt;
};