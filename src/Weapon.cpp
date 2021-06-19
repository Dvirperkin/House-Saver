#include "Weapon.h"

Weapon::Weapon():m_fireRate(START_FIRE_RATE), m_bulletDamage(START_BULLET_DAMAGE){}
//===============================================================
void Weapon::shoot(sf::Vector2f pos,b2World &world, Side_t side)
{
    if (m_clock.getElapsedTime().asSeconds() >= m_fireRate) {
        m_bullets.emplace_back(std::make_unique<Bullet>(pos, world, side,m_bulletDamage));
        m_clock.restart();
    } 
}
//===============================================================
void Weapon::setFireRate(const float& fireRate)
{
    m_fireRate = fireRate;
}
void Weapon::setBulletDamage(const float & bulletDamage)
{
    m_bulletDamage = bulletDamage;
}
//===============================================================
void Weapon::bulletCheck(){
   for (size_t i = 0; i < m_bullets.size(); i++) {
       if (m_bullets[i]->shoot()) {
            m_bullets.erase(m_bullets.begin());
            --i;
        }
    }
}

void Weapon::drawBullet(sf::RenderWindow& window, sf::Time deltaTime) {
    for (auto& bullet : m_bullets) {
        bullet->draw(window);
        bullet->update(deltaTime);
    }
}
