#include "MovingObject.h"

MovingObject::MovingObject(const sf::Sprite &sprite, const sf::Vector2f &pos, b2World & world,
                           std::unique_ptr<Animation> animation) :
                           GameObject(sprite, pos, world, std::move(animation)), m_side(Side_t::RIGHT){

}
//=====================================================================
void MovingObject::moveX(float desiredVelX, float desiredVelY) {
    b2Vec2 vel = getBodyLinearVelocity();
    float velChangeX = desiredVelX - vel.x;
    float impulseX = getBodyMass() * velChangeX; //disregard time factor
    m_body->ApplyLinearImpulse(b2Vec2(impulseX, 0), m_body->GetWorldCenter(), true);
}
//=============================================================================
void MovingObject::moveY(float desiredVelX, float desiredVelY) {
    b2Vec2 vel = getBodyLinearVelocity();
    float velChangeY = desiredVelY - vel.y;
    float impulseY = getBodyMass() * velChangeY; //disregard time factor
    m_body->ApplyLinearImpulse(b2Vec2(0, impulseY), m_body->GetWorldCenter(), true);
}
//=============================================================================
void MovingObject::opposite(enum Side_t side) {
    if(side != m_side) {
        m_sprite.scale(-1, 1);
        m_side = side;
    }
}
//=============================================================================

