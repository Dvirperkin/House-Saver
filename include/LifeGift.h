#pragma once
#include "Gift.h"

class LifeGift : public Gift {
public:
	LifeGift(const sf::Vector2f&, b2World&, const sf::Vector2f&);
	Objects_t getBodyType() const override { return LIFE_GIFT; }
	int giveLife() { return 1; };

private:
	static bool m_registerIt;
};