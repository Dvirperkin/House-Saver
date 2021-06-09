#include "MovingObject.h"

MovingObject::MovingObject(const sf::Sprite& sprite, const sf::Vector2f& pos, b2World&) :GameObject(sprite, pos) {}

//=====================================================================
void MovingObject::move(float desiredVelX, float desiredVelY)
{
	b2Vec2 vel = m_body->GetLinearVelocity();
	float velChangeX = desiredVelX - vel.x;
	float velChangeY = desiredVelY - vel.y;
	float impulseX = m_body->GetMass() * velChangeX; //disregard time factor
	float impulseY = m_body->GetMass() * velChangeY; //disregard time factor
	m_body->ApplyLinearImpulse(b2Vec2(impulseX, impulseY), m_body->GetWorldCenter(), true);
	//m_body->ApplyForceToCenter(b2Vec2(dir.x * delta.asMilliseconds(), dir.y * delta.asMilliseconds()), true);
}
