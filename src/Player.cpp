#include "Player.h"

Player::Player(const sf::Vector2f & pos, b2World & world) :
                MovingObject(Textures::texturesObject().getSprite(PLAYER_T), pos, world),
                m_animation(Textures::texturesObject().animationData(PLAYER_D), Direction::Idle,
                            m_sprite){

    b2Vec2 position(pos.x, pos.y);

    b2Vec2 dimensions(0.49 - b2_polygonRadius, 0.49 - b2_polygonRadius);

    rigidBody(world, position, dimensions, b2_dynamicBody);
}
//=========================================================================================
void Player::move() {
   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        m_body->ApplyForceToCenter(b2Vec2(0,-15), true);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        m_body->ApplyForceToCenter(b2Vec2(0,15), true);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        m_body->ApplyForceToCenter(b2Vec2(-15,0), true);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        m_body->ApplyForceToCenter(b2Vec2(15,0), true);
    }
    else
        m_movement = Direction::Idle;

    auto position = m_body->GetPosition();
    position *= 50;

    setPos({position.x, position.y});
}
//=========================================================================================
void Player::update(sf::Time deltaTime) {
    m_animation.update(deltaTime);
}
//=========================================================================================