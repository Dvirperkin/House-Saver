#pragma once

#include "MovingObject.h"
#include "Weapon.h"
#include "Bullet.h"

class Key;
class Elevator;
class Door;


// A class that represents a player.

class Player : public MovingObject {
public:

    Player(const sf::Vector2f& pos, b2World&);

    void move();
    void use();

    Objects_t getBodyType() const override {return PLAYER;};

    void drawBullet(sf::RenderWindow& ,sf::Time);
    bool isDead();

    //----------Contacts Section----------
    void startContact(Key *);
    void startContact(Enemy *);
    void startContact(Door *);
	void startContact(Elevator *);

    void endContact(Door *);
	void endContact(Elevator *);

private:
    static bool m_registerIt;

    float m_hp = 100;
    Elevator * m_elevator;
    unsigned int m_keys = 0;
    Side_t m_side = Side_t::RIGHT;

    Weapon m_weapon;
    AnimationStatus_t m_movement = AnimationStatus_t::Idle;
};
