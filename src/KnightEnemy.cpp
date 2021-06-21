#include "KnightEnemy.h"
#include "Factory.h"

// Registers the KnightEnemy object to the objects factory.

bool KnightEnemy::m_registerIt = Factory<Enemy>::registerObject(ENEMY, [](const sf::Vector2f &pos,
                                                                b2World &world, const sf::Vector2f & dimension) -> std::shared_ptr<Enemy> {
    return std::make_shared<KnightEnemy>(pos, world, dimension);
});
//=============================================================================
KnightEnemy::KnightEnemy(const sf::Vector2f& pos, b2World& world, const sf::Vector2f & dimension):
    Enemy(pos,world, dimension){}
//=============================================================================
AnimationStatus_t KnightEnemy::move(){

    b2Vec2 desiredVel(0,0);
    if (getBody()->GetLinearVelocity().x >= 0)
        desiredVel.x = 2;

    else
        desiredVel.x = -2;

    setDirection(desiredVel);
	return Enemy::move();
}
//=============================================================================