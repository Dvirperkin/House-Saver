#pragma once

#include <memory>

#include "Bullet.h"

// A class that implements a weapon object.

class Weapon {
public:

    //----------Constructors\Destructors Section----------
	Weapon(const sf::Vector2f &,const int);

    //----------Functions Section----------
	void shoot(sf::Vector2f, b2World &, Side_t = Side_t::RIGHT);
	void setFireRate(const float &);
    void setBulletVelocity(const float &);
	void bulletCheck();
	void drawBullet(sf::RenderWindow&, sf::Time);
	void increaseBulletDamage();

private:
	int m_toHit;
	sf::Vector2f m_dimension;
	sf::Clock m_clock;
	float m_bulletDamage;
	float m_fireRate;
    float m_bulletVelocity = BULLET_VELOCITY;
	std::vector<std::unique_ptr<Bullet>> m_bullets;
};