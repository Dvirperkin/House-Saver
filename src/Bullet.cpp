#include "Bullet.h"

Bullet::Bullet(const sf::Vector2f & pos, b2World & world,const Side_t& sideToShoot, const float& hitPoint):m_sideToShoot(sideToShoot),
        m_hitPoint(hitPoint),MovingObject(Textures::texturesObject().getSprite(BULLET_T), pos, world){
    auto to_add = 0;
    if (m_sideToShoot == Side_t::RIGHT) {
        m_desiredVel = 8;
        to_add = getGlobalBounds().width / 2;
    }
        
    else {
        m_desiredVel = -8;
        to_add -= getGlobalBounds().width / 2;
        opposite(Side_t::LEFT);
    }
    auto objectPosition = sf::Vector2f{ ((pos.x + to_add) * HOUSE_OBJECT_CAPACITY.first - getGlobalBounds().width / 2) / WINDOW_SIZE.first,
                        ((pos.y - getGlobalBounds().height/4) * HOUSE_OBJECT_CAPACITY.second - getGlobalBounds().height / 2) / WINDOW_SIZE.second };
    setPos(objectPosition);
    b2Vec2 position(objectPosition.x, objectPosition.y);
    m_sprite.setScale(m_sprite.getScale().x / 3, m_sprite.getScale().y / 5);
    b2CircleShape circleShape;
    circleShape.m_radius = 0.48 - b2_polygonRadius;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 2.f;
    fixtureDef.friction = 2.f;
    fixtureDef.isSensor = 1;
    rigidBody(world, position, fixtureDef, b2_dynamicBody);

    setUserData();

    setFixedRotation(true);
    
    m_clock.restart();
}
//=========================================================================================
bool Bullet::shoot(){
    sf::Time deltaTime;
    deltaTime = m_clock.getElapsedTime();
    if (deltaTime.asSeconds() >= BULLET_DISTANCE) {m_disposed = true;}
    moveX(m_desiredVel, 0);
    moveY(ANTI_GRAVITY.x, ANTI_GRAVITY.y);
    return m_disposed;
}
//=========================================================================================