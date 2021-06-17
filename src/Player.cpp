#include "Player.h"
#include <iostream>
#include "Enemy.h"
Player::Player(const sf::Vector2f& pos, b2World& world) :
    MovingObject(Textures::texturesObject().getSprite(PLAYER_T), pos, world,
                 std::make_unique<Animation>(Textures::texturesObject().animationData(PLAYER_D),
                                             AnimationStatus_t::Idle, m_sprite)){
    b2Vec2 position(pos.x, pos.y);

    b2CircleShape circleShape;
    circleShape.m_radius = 0.48 - b2_polygonRadius;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 2.f;
    fixtureDef.friction = 0.f;

    rigidBody(world, position, fixtureDef, b2_dynamicBody);

    setUserData();

    setFixedRotation(true);
}
//=========================================================================================
AnimationStatus_t Player::move() {
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        && m_movement != AnimationStatus_t::Jump && m_movement != AnimationStatus_t::Falling) {
        moveY(0, -DESIREDVEL);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

        moveX(-DESIREDVEL, 0);
        m_side = opposite(Side_t::LEFT);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        moveX(DESIREDVEL, 0);
        m_side = opposite(Side_t::RIGHT);
    }
    else {
        moveX(0, 0);
        m_movement = AnimationStatus_t::Idle;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
        m_weapon.shoot(getPos(), *m_body->GetWorld(), m_side);
        m_movement = AnimationStatus_t::Shoot;
    }
    if (m_body->GetLinearVelocity().y < 0)
        m_movement = AnimationStatus_t::Jump;
    else if (m_body->GetLinearVelocity().y > 0)
        m_movement = AnimationStatus_t::Falling;
    else if (m_body->GetLinearVelocity().x != 0)
        m_movement = AnimationStatus_t::Walk;

    else{
        if (m_movement != AnimationStatus_t::Shoot)
                m_movement = AnimationStatus_t::Idle;
    }
    m_weapon.bulletCheck();

    setAnimationStatus(m_movement);
  
    return m_movement;

}
//=========================================================================================
void Player::drawBullet(sf::RenderWindow& window,sf::Time deltaTime) {
    m_weapon.drawBullet(window,deltaTime);
}
//=========================================================================================
bool Player::isDead()
{
    if (m_hp <= 0)
        return true;
    return false;
}
//=========================================================================================
void Player::startContact(Key* key) {
    ++m_keys;
    key->take();
    std::cout << m_keys << std::endl;
}
//=========================================================================================
void Player::startContact(Enemy* enemy) {
    m_hp -= enemy->getHit();
    moveY(0, 3);

}