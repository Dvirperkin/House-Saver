#include "Player.h"
#include <iostream>

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
    float desiredVel = 0;
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up ) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        && m_movement != AnimationStatus_t::Jump && m_movement != AnimationStatus_t::Falling) {
        desiredVel = -5;
        moveY(0, desiredVel);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        desiredVel = -5;
        moveX(desiredVel,0);
        opposite(Side_t::LEFT);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        desiredVel = 5;
        moveX(desiredVel,0);
        opposite(Side_t::RIGHT);
    }
    else {
        moveX(0,0); 
    }
    if (m_body->GetLinearVelocity().y < 0)
        m_movement = AnimationStatus_t::Jump;
    else if (m_body->GetLinearVelocity().y > 0)
        m_movement = AnimationStatus_t::Falling;
    else if (m_body->GetLinearVelocity().x != 0)
        m_movement = AnimationStatus_t::Walk;
    else
        m_movement = AnimationStatus_t::Idle;

    setAnimationStatus(m_movement);
  
    return m_movement;

}
//=========================================================================================
void Player::startContact(Key * key) {
    ++m_keys;
    key->take();
    std::cout <<  m_keys << std::endl;
}
//=========================================================================================