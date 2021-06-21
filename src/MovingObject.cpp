#include "MovingObject.h"

MovingObject::MovingObject(const sf::Sprite &sprite, const sf::Vector2f & pos, b2World & world,
                           const sf::Vector2f & dimension,
                           std::unique_ptr<Animation> animation) :
                           GameObject(sprite, pos, world, dimension, std::move(animation)), m_side(Side_t::RIGHT){

}
//=====================================================================
void MovingObject::draw(sf::RenderWindow& window, sf::Time deltaTime){
    GameObject::draw(window);
}
//=====================================================================
void MovingObject::moveX(float desiredVelX) {
    b2Vec2 vel = getBodyLinearVelocity();
    float velChangeX = desiredVelX - vel.x;
    float impulseX = getBodyMass() * velChangeX; //disregard time factor
    getBody()->ApplyLinearImpulse(b2Vec2(impulseX, 0), getBody()->GetWorldCenter(), true);
}
//=============================================================================
void MovingObject::moveY(float desiredVelY) {
    b2Vec2 vel = getBodyLinearVelocity();
    float velChangeY = desiredVelY - vel.y;
    float impulseY = getBodyMass() * velChangeY; //disregard time factor
    getBody()->ApplyLinearImpulse(b2Vec2(0, impulseY), getBody()->GetWorldCenter(), true);
}
//=============================================================================
Side_t MovingObject::opposite(enum Side_t side) {
    if(side != m_side) {
        getSprite().scale(-1, 1);
        m_side = side;
    }
    return m_side;
}
//=============================================================================

