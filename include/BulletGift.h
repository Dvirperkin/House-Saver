#pragma once
#include "Gift.h"

class BulletGift : public Gift {
public:
	BulletGift(const sf::Vector2f&, b2World&, const sf::Vector2f&);
	Objects_t getBodyType() const override { return BULLET_GIFT; }
	int giveLife() { return 50; };

private:
	static bool m_registerIt;
};
