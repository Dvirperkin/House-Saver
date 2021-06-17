#include "KnightEnemy.h"
#include "Factory.h"

// Registers the KnightEnemy object to the objects factory.

bool KnightEnemy::m_registerIt = Factory::registerObject('E', [](const sf::Vector2f &pos,
                                                                b2World &world) -> std::unique_ptr<GameObject> {
    return std::make_unique<KnightEnemy>(pos, world);
});
//=============================================================================
KnightEnemy::KnightEnemy(const sf::Vector2f& pos, b2World& world):Enemy(pos,world){}
//=============================================================================
AnimationStatus_t KnightEnemy::move(){

    b2Vec2 desiredVel(0,0);
    if (m_body->GetLinearVelocity().x >= 0)
        desiredVel.x = 2;

    else
        desiredVel.x = -2;

    setDirection(desiredVel);
	return Enemy::move();
}
//=============================================================================