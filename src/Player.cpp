#include "Player.h"

Player::Player(const sf::Vector2f& pos, b2World& world) :
    MovingObject(Textures::texturesObject().getSprite(PLAYER_T), pos,
                 std::make_unique<Animation>(Textures::texturesObject().animationData(PLAYER_D),
                                             AnimationStatus_t::Idle, m_sprite)){
    b2Vec2 position(pos.x, pos.y);

    b2Vec2 dimensions(0.48 - b2_polygonRadius, 0.48 - b2_polygonRadius);
    
    rigidBody(world, position, dimensions, b2_dynamicBody);

    setFixedRotation(true);
}
//=========================================================================================
AnimationStatus_t Player::move() {

    auto movement = AnimationStatus_t::Idle;

    float desiredVel = 0;
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
        //m_body->ApplyForceToCenter(b2Vec2(0, -80), false);
        desiredVel = -5;
        MovingObject::move(0, desiredVel);
        movement = AnimationStatus_t::Jump;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        desiredVel = 5;
        MovingObject::move(0, desiredVel);
        movement = AnimationStatus_t::Walk;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        desiredVel = -5;
        MovingObject::move(desiredVel,0);
        movement = AnimationStatus_t::Walk;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        desiredVel = 5;
        MovingObject::move(desiredVel,0);
        movement = AnimationStatus_t::Walk;
    }
    else {
        MovingObject::move(0,0);
    }

    setAnimationStatus(movement);

    auto position = getBodyPos();
    //auto factor = (HOUSE_SIZE.first / HOUSE_OBJECT_CAPACITY.first) / position.x;
    position.x *= HOUSE_SIZE.first / HOUSE_OBJECT_CAPACITY.first;
    position.y *= HOUSE_SIZE.second / HOUSE_OBJECT_CAPACITY.second;
    position.y += 10;
    setPos({ position.x, position.y});

    return movement;

}
//=========================================================================================