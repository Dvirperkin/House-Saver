#pragma once
#include "Enemy.h"

class KnightEnemy : public Enemy {
	public:
		KnightEnemy(const sf::Vector2f&, b2World&);
		AnimationStatus_t move();
};