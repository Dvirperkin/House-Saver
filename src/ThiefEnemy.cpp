#include "ThiefEnemy.h"

// Registers the ThiefEnemy object to the objects factory.

bool ThiefEnemy::m_registerIt = Factory<Enemy>::registerObject(THIEF_ENEMY, [](const sf::Vector2f &pos,
                                                                               b2World &world, const sf::Vector2f & dimension) -> std::shared_ptr<Enemy> {
    return std::make_shared<ThiefEnemy>(pos, world, dimension);
});
//=============================================================================
ThiefEnemy::ThiefEnemy(const sf::Vector2f& pos, b2World& world, const sf::Vector2f & dimension):
    Enemy(Textures::texturesObject().getSprite(KNIGHT_ENEMY_T), pos, world, dimension,
          std::make_unique<Animation>(Textures::texturesObject().animationData(KNIGHT_ENEMY_D),
                                      AnimationStatus_t::Idle,
                                      getSprite(), dimension)){}
//=============================================================================
AnimationStatus_t ThiefEnemy::move(sf::Vector2f playerPosition){

    b2Vec2 desiredVel(0,0);
    if (getBody()->GetLinearVelocity().x >= 0)
        desiredVel.x = ENEMY_VELOCITY;

    else
        desiredVel.x = -ENEMY_VELOCITY;

    setDirection(desiredVel);
    return Enemy::move(playerPosition);
}
//=============================================================================