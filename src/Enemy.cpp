#include "Enemy.h"

//=============================================================================
Enemy::Enemy(const sf::Sprite & sprite, const sf::Vector2f & pos, b2World & world, const sf::Vector2f & dimension,
             std::unique_ptr<Animation> animation) :
    MovingObject(sprite, pos, world, dimension,
                 std::move(animation)), m_dir(0,0) ,m_hp(100){
    b2Vec2 position(pos.x, pos.y);

    b2CircleShape circleShape;
    circleShape.m_radius = 0.48 - b2_polygonRadius;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 2.f;
    fixtureDef.friction = 0.f;
    fixtureDef.restitution = 0.2f;
    fixtureDef.filter.groupIndex = -1;
    rigidBody(world, position, fixtureDef, b2_dynamicBody);

    setUserData();

    setFixedRotation(true);
}
//=========================================================================================
AnimationStatus_t Enemy::move(sf::Vector2f playerPosition) {
    if (m_dir.x == 0)
        m_movement = AnimationStatus_t::Shoot;
    else
        m_movement = AnimationStatus_t::Walk;

    if (m_hitted) {
        m_movement = AnimationStatus_t::Hurt;
        moveX(HIT_MOVE*m_side);
        moveY(HIT_MOVE);
        m_hitted = false;
    }
    if (getPos().y - playerPosition.y > -10 && getPos().y - playerPosition.y < 10 && m_movement != AnimationStatus_t::Shoot) {
        if (playerPosition.x < getPos().x) {
            m_dir.x = -2;
        }
        else {
            m_dir.x = 2;
        }
    }
    if (m_dir.y < 0 && m_movement != AnimationStatus_t::Shoot){
        moveY(m_dir.y);
    }
    else if (m_dir.x < 0 && m_movement != AnimationStatus_t::Shoot) {
        moveX(m_dir.x);
        opposite(Side_t::LEFT);
    }

    else if (m_dir.x > 0 && m_movement != AnimationStatus_t::Shoot) {
        moveX(m_dir.x);
        opposite(Side_t::RIGHT);
    }
    else {
        moveX(0);
    }
   
    setAnimationStatus(m_movement);

    return m_movement;
}
//=========================================================================================
void Enemy::setDirection(const b2Vec2 & dir){
    m_dir = dir;
}
//=========================================================================================
b2Vec2 Enemy::getDirection() const{
    return m_dir;
}
//=========================================================================================
void Enemy::startContact(Player* player) {

}
//=========================================================================================
void Enemy::startContact(Bullet* bullet){
    if (bullet->getBodyLinearVelocity().x >= 0)
        m_side *= 1;
    else
        m_side *= -1;

    m_hitted = true;
    m_hp -= bullet->getHit();
    bullet->hit();
}
//=========================================================================================
bool Enemy::isDead() {
    if (m_hp <= 0)
        return true;
    return false;
}
//=========================================================================================
