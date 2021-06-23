#include "Bullet.h"

Bullet::Bullet(const sf::Vector2f & pos, b2World & world, const sf::Vector2f & dimension,
               const Side_t& sideToShoot, const float & hitPoint, const float & desiredVel,const int toHit):
               m_sideToShoot(sideToShoot), m_desiredVel(desiredVel), m_hitPoint(hitPoint),
               MovingObject(Textures::texturesObject().getSprite(BULLET_T), pos, world,dimension){
    auto to_add = 0;
    if (m_sideToShoot == Side_t::RIGHT) {
        m_desiredVel *= 1;
        to_add = getGlobalBounds().width / 2;
    }
        
    else {
        m_desiredVel *= -1;
        to_add -= getGlobalBounds().width / 2;
        opposite(Side_t::LEFT);
    }

    auto objectPosition = sf::Vector2f{ ((pos.x + to_add) * dimension.x - getGlobalBounds().width / 2) / WINDOW_SIZE.first,
                        ((pos.y - getGlobalBounds().height/4) * dimension.y - getGlobalBounds().height / 2) / WINDOW_SIZE.second };
    setPos(objectPosition);
    b2Vec2 position(objectPosition.x, objectPosition.y);
    getSprite().setScale(getSprite().getScale().x / 3, getSprite().getScale().y / 5);
    b2CircleShape circleShape;
    circleShape.m_radius = 0.48 / 3 - b2_polygonRadius;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 2.f;
    fixtureDef.friction = 2.f;
    fixtureDef.isSensor = 1;
    fixtureDef.filter.groupIndex = toHit;
    rigidBody(world, position, fixtureDef, b2_dynamicBody);

    setUserData();

    setFixedRotation(true);
    
    m_clock.restart();
}
//=========================================================================================
bool Bullet::shoot(){
    auto deltaTime = m_clock.getElapsedTime();
    if (deltaTime.asSeconds() >= BULLET_DISTANCE) {m_disposed = true;}
    moveX(m_desiredVel);
    moveY(ANTI_GRAVITY.y);
    return m_disposed;
}
//=========================================================================================