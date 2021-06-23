#pragma once

#include "MovingObject.h"
#include "PlayerStats.h"
#include "Weapon.h"
#include "Bullet.h"


class Key;
class Elevator;
class Door;
class HpGift;
class BulletGift;
class LifeGift;
// A class that represents a player.

class Player : public MovingObject {
public:

    Player(const sf::Vector2f & pos, b2World &, const sf::Vector2f &, PlayerStats &);

    void move();
    sf::Keyboard::Key use();

    Objects_t getBodyType() const override {return PLAYER;};
    Door * getDoor() const {return m_door;}
    Elevator* getElevator() const { return m_elevator; }
    int getKeyCollected() const;
    void draw(sf::RenderWindow &, sf::Time) override;
    bool isDead();

    //----------Contacts Section----------
    void startContact(Key *);
    void startContact(Enemy *);
    void startContact(Door *);
	void startContact(Elevator *);
    void startContact(HpGift *);
    void startContact(BulletGift *);
	void startContact(Bullet *);
    void startContact(LifeGift *);

    void endContact(Door *);
	void endContact(Elevator *);


private:
    static bool m_registerIt;

    PlayerStats & m_stats;

    float m_hp = START_HP;
    Door * m_door = nullptr;
    Elevator * m_elevator = nullptr;
    Side_t m_side = Side_t::RIGHT;

    Weapon m_weapon;
    AnimationStatus_t m_movement = AnimationStatus_t::Idle;
};
