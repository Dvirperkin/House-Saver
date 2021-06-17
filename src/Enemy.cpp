#include "Enemy.h"

//=============================================================================
Enemy::Enemy(const sf::Vector2f& pos, b2World& world) :
    MovingObject(Textures::texturesObject().getSprite(ENEMY_T), pos, world,
        std::make_unique<Animation>(Textures::texturesObject().animationData(ENEMY_D),
            AnimationStatus_t::Idle, m_sprite)),m_dir(0,0) ,m_hp(300){

    b2Vec2 position(pos.x, pos.y);

    b2CircleShape circleShape;
    circleShape.m_radius = 0.48 - b2_polygonRadius;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 2.f;
    fixtureDef.friction = 0.f;
    fixtureDef.restitution = 0.2f;
    rigidBody(world, position, fixtureDef, b2_dynamicBody);

    setUserData();

    setFixedRotation(true);
}
//=========================================================================================
AnimationStatus_t Enemy::move() {

    if (m_hitted) {
        moveX(HIT_MOVE, 0);
        moveY(0, HIT_MOVE);
        m_hitted = false;
    }

    else if (m_dir.y < 0){
        moveY(0, m_dir.y);
    }
    else if (m_dir.x < 0 ) {      
        moveX(m_dir.x, 0);
        opposite(Side_t::LEFT);
    }

    else if (m_dir.x > 0) {
        moveX(m_dir.x, 0);
        opposite(Side_t::RIGHT);
    }
    else {
        moveX(0, 0);
    }
    m_movement = AnimationStatus_t::Walk;
 
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
