#pragma once
#include "Bullet.h"

class Weapon {
public:
	Weapon(const sf::Vector2f &);
	void shoot(sf::Vector2f, b2World &, Side_t = Side_t::RIGHT);
	void setFireRate(const float&);
	void setBulletDamage(const float&);
    void setBulletVelocity(const float&);
	void bulletCheck();
	void drawBullet(sf::RenderWindow&, sf::Time);
	void increaseBulletDamage();
private:
	sf::Vector2f m_dimension;
	sf::Clock m_clock;
	float m_bulletDamage;
	float m_fireRate;
    float m_bulletVelocity = 8;
	std::vector<std::unique_ptr<Bullet>> m_bullets;
};