#pragma once

#include "Enemy.h"
#include "Weapon.h"

// A class that represents a shooting-type enemy

class ShooterEnemy : public Enemy {
public:
    //----------Constructors\Destructors Section----------
    ShooterEnemy(const sf::Vector2f&, b2World&, const sf::Vector2f&);

    //----------Functions Section----------
    AnimationStatus_t move(sf::Vector2f);

    Objects_t getBodyType() const override { return SHOOTER_ENEMY; }

    void draw(sf::RenderWindow& window, sf::Time)override;

private:
    Side_t FindDirectionToShoot(sf::Vector2f);
    static bool m_registerIt;
    Weapon m_weapon;

};