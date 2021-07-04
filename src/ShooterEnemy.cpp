#include "ShooterEnemy.h"

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
    m_weapon.setFireRate(ENEMY_FIRE_RATE);
    m_weapon.setBulletVelocity(ENEMY_BULLET_VELOCITY);
}
//=============================================================================
AnimationStatus_t ShooterEnemy::move(sf::Vector2f playerPosition) {

    b2Vec2 desiredVel(0, 0);

    // Checks if the position of the player relative to the enemy is in the define shooting range.
    if (getPos().y - playerPosition.y > -PLAYER_ENEMY_RANGE && getPos().y - playerPosition.y < PLAYER_ENEMY_RANGE &&
        (getPos().x - playerPosition.x < SHOOTING_RANGE && getPos().x - playerPosition.x > -SHOOTING_RANGE)) {

        // While the enemy is alive he can shoot the player.
        if (getMovement() != AnimationStatus_t::Death) {
            m_weapon.shoot(getPos(), *getBody()->GetWorld(), FindDirectionToShoot(playerPosition));
            Sounds::soundObject().playSound(Sounds_t::SHOOT_SOUND);
        }
    }
    // Determent the direction of the enemy.
    else if (getBody()->GetLinearVelocity().x >= 0)
        desiredVel.x = ENEMY_VELOCITY;
    else
        desiredVel.x = -ENEMY_VELOCITY;

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
//=============================================================================