#include "Weapon.h"

Weapon::Weapon(const sf::Vector2f & dimension):m_fireRate(START_FIRE_RATE),
                                            m_bulletDamage(START_BULLET_DAMAGE), m_dimension(dimension){}
//===============================================================
void Weapon::shoot(sf::Vector2f pos, b2World & world, Side_t side){

    if (m_clock.getElapsedTime().asSeconds() >= m_fireRate) {
        m_bullets.emplace_back(std::make_unique<Bullet>(pos, world,
                                                        m_dimension,
                                                        side, m_bulletDamage, m_bulletVelocity));
        m_clock.restart();
    } 
}
//===============================================================
void Weapon::setFireRate(const float& fireRate){
    m_fireRate = fireRate;
}
//===============================================================
void Weapon::setBulletDamage(const float & bulletDamage){
    m_bulletDamage = bulletDamage;
}
//===============================================================
void Weapon::setBulletVelocity(const float& bulletVelocity){
    m_bulletVelocity = bulletVelocity;
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
//===============================================================
void Weapon::drawBullet(sf::RenderWindow& window, sf::Time deltaTime) {
    for (auto& bullet : m_bullets) {
        bullet->draw(window, deltaTime);
        bullet->update(deltaTime, m_dimension);
    }
}
void Weapon::increaseBulletDamage()
{
    m_bulletDamage += 5;
}
//===============================================================