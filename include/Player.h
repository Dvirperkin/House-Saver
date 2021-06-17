#pragma once

#include "MovingObject.h"
#include "Key.h"
#include "Weapon.h"
#include "Bullet.h"

class Player : public MovingObject {
public:

    Player(const sf::Vector2f& pos, b2World&);
    AnimationStatus_t move();

    Objects_t getBodyType() const override {return PLAYER;};

    void drawBullet(sf::RenderWindow& ,sf::Time);
    bool isDead();
    void startContact(Key*);
    void startContact(Enemy*);

private:
    Side_t m_side = Side_t::RIGHT;
    float m_hp = 100;
    unsigned int m_keys = 0;
    Weapon m_weapon;
    std::vector<std::unique_ptr<Bullet>> m_bullets;
    AnimationStatus_t m_movement = AnimationStatus_t::Idle;
};
