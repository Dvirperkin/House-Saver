#pragma once
#include "Gift.h"

class HpGift : public Gift {
public:
	HpGift(const sf::Vector2f&, b2World&, const sf::Vector2f&);
	Objects_t getBodyType() const override { return HP_GIFT; }
	int giveHP() { return 30; };

private:
	static bool m_registerIt;

};