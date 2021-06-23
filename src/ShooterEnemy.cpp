#include "ShooterEnemy.h"
#include "Factory.h"

// Registers the ShooterEnemy object to the objects factory.

bool ShooterEnemy::m_registerIt = Factory<Enemy>::registerObject(SHOOTER_ENEMY, [](const sf::Vector2f& pos,
        b2World& world, const sf::Vector2f& dimension) -> std::shared_ptr<Enemy> {

        return std::make_shared<ShooterEnemy>(pos, world, dimension);
});
//=============================================================================
ShooterEnemy::ShooterEnemy(const sf::Vector2f& pos, b2World& world, const sf::Vector2f& dimension) :m_weapon(dimension,-1),
    Enemy(Textures::texturesObject().getSprite(SHOOTER_ENEMY_T), pos, world, dimension,
          std::make_unique<Animation>(Textures::texturesObject().animationData(SHOOTER_ENEMY_D),
                                      AnimationStatus_t::Walk,
                                      getSprite(), dimension)) {
    m_weapon.setFireRate(0.7f);
    m_weapon.setBulletVelocity(6);
}
//=============================================================================
AnimationStatus_t ShooterEnemy::move(sf::Vector2f playerPosition) {

    b2Vec2 desiredVel(0, 0);
    if (getPos().y - playerPosition.y > -10 && getPos().y - playerPosition.y < 10 &&
        (getPos().x - playerPosition.x < 300 && getPos().x - playerPosition.x > -300)) {
        Sounds::soundObject().playSound(Sounds_t::SHOOT_SOUND);
        m_weapon.shoot(getPos(), *getBody()->GetWorld(), FindDirectionToShoot(playerPosition));
        desiredVel.x = 0;
    }
    else if (getBody()->GetLinearVelocity().x >= 0)
        desiredVel.x = 2;

    else
        desiredVel.x = -2;


    m_weapon.bulletCheck();
    setDirection(desiredVel);
    return Enemy::move(playerPosition);
}
//=============================================================================
Side_t ShooterEnemy::FindDirectionToShoot(sf::Vector2f playerPosition) {
    if (playerPosition.x < getPos().x)
        return Side_t::LEFT;
    return Side_t::RIGHT;
}
//=============================================================================
void ShooterEnemy::draw(sf::RenderWindow& window,sf::Time deltaTime) {
    MovingObject::draw(window, deltaTime);
    m_weapon.drawBullet(window, deltaTime);
}