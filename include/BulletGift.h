#pragma once

#include "Gift.h"

// A class that represent a bullet gift that increases bullet damage.

class BulletGift : public Gift {
public:
    //--------------------Constructor/Destructor Section--------------------
	BulletGift(const sf::Vector2f&, b2World&, const sf::Vector2f&);

    //--------------------Functions Section--------------------
	Objects_t getBodyType() const override { return BULLET_GIFT; }

private:
	static bool m_registerIt;
};