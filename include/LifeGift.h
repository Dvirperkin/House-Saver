#pragma once

#include "Gift.h"

// A class that implements a gift of life.

class LifeGift : public Gift {
public:
    //----------Constructors\Destructors Section----------
	LifeGift(const sf::Vector2f&, b2World&, const sf::Vector2f&);

    //----------Functions Section----------
	Objects_t getBodyType() const override { return LIFE_GIFT; }

private:
	static bool m_registerIt;
};