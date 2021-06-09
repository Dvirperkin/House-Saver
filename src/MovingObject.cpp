#include "MovingObject.h"

MovingObject::MovingObject(const sf::Sprite &sprite, const sf::Vector2f &pos,
                           std::unique_ptr<Animation> animation) :
                           GameObject(sprite, pos, std::move(animation)){

}
//=====================================================================
void MovingObject::move(float desiredVelX, float desiredVelY)
{
	b2Vec2 vel = getBodyLinearVelocity();
	float velChangeX = desiredVelX - vel.x;
	float velChangeY = desiredVelY - vel.y;
	float impulseX = getBodyMass() * velChangeX; //disregard time factor
	float impulseY = getBodyMass() * velChangeY; //disregard time factor
	m_body->ApplyLinearImpulse(b2Vec2(impulseX, impulseY), m_body->GetWorldCenter(), true);

	//m_body->ApplyForceToCenter(b2Vec2(dir.x * delta.asMilliseconds(), dir.y * delta.asMilliseconds()), true);
}


