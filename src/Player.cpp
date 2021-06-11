#include "Player.h"
#include <iostream>

Player::Player(const sf::Vector2f& pos, b2World& world) :
    MovingObject(Textures::texturesObject().getSprite(PLAYER_T), pos, world,
                 std::make_unique<Animation>(Textures::texturesObject().animationData(PLAYER_D),
                                             AnimationStatus_t::Idle, m_sprite)){
    b2Vec2 position(pos.x, pos.y);

    b2Vec2 dimensions(0.48 - b2_polygonRadius, 0.48 - b2_polygonRadius);
    
    rigidBody(world, position, dimensions, b2_dynamicBody);

    setUserData();

    setFixedRotation(true);
}
//=========================================================================================
AnimationStatus_t Player::move() {

    auto movement = AnimationStatus_t::Idle;

    float desiredVel = 0;
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
        desiredVel = -5;
        moveX(0, desiredVel);
        movement = AnimationStatus_t::Jump;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        desiredVel = 5;
        moveX(0, desiredVel);
        movement = AnimationStatus_t::Idle;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        desiredVel = -5;
        moveX(desiredVel,0);
        movement = AnimationStatus_t::Walk;
        opposite(Side_t::LEFT);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        desiredVel = 5;
        moveX(desiredVel,0);
        movement = AnimationStatus_t::Walk;
        opposite(Side_t::RIGHT);
    }
    else {
        moveX(0,0);
    }

    setAnimationStatus(movement);

    return movement;

}
//=========================================================================================
void Player::startContact(Key * key) {
    ++m_keys;
    key->take();
    std::cout <<  m_keys << std::endl;
}
//=========================================================================================