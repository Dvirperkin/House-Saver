#include "Player.h"

Player::Player(const sf::Vector2f& pos, b2World& world) :
    MovingObject(Textures::texturesObject().getSprite(PLAYER_T), pos, world),
    m_animation(Textures::texturesObject().animationData(PLAYER_D), Direction::Idle,
        m_sprite) {

    b2Vec2 position(pos.x, pos.y);

    b2Vec2 dimensions(0.49 - b2_polygonRadius, 0.49 - b2_polygonRadius);

    rigidBody(world, position, dimensions, b2_dynamicBody);
}
//=========================================================================================
void Player::move() {
    
    float desiredVel = 0;
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))&&m_body->GetContactList() != 0) {
        //m_body->ApplyForceToCenter(b2Vec2(0, -80), false);
        desiredVel = -10;
        MovingObject::move(0, desiredVel);
        m_movement = Direction::Jump;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        desiredVel = 5;
        MovingObject::move(0, desiredVel);
        MovingObject::move(0, 0);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        desiredVel = -5;
        MovingObject::move(desiredVel,0);
        m_movement = Direction::Walk;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        desiredVel = 5;
        MovingObject::move(desiredVel,0);
        m_movement = Direction::Walk;
    }
    else {
        MovingObject::move(0,0);
        m_movement = Direction::Idle;
    }
    
    
    m_animation.direction(m_movement);
    auto position = m_body->GetPosition();
    //auto factor = (HOUSE_SIZE.first / HOUSE_OBJECT_CAPACITY.first) / position.x;
    position.x *= HOUSE_SIZE.first / HOUSE_OBJECT_CAPACITY.first;
    position.y *= HOUSE_SIZE.second / HOUSE_OBJECT_CAPACITY.second;
    setPos({ position.x, position.y });
}
//=========================================================================================
void Player::update(sf::Time deltaTime) {
    m_animation.update(deltaTime);
}
//=========================================================================================