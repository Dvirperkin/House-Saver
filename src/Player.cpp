#include "Player.h"
#include "Enemy.h"
#include "Factory.h"

// Registers the Player object to the objects factory.

bool Player::m_registerIt = Factory::registerObject('P', [](const sf::Vector2f &pos,
                                                                b2World &world) -> std::unique_ptr<GameObject> {
    return std::make_unique<Player>(pos, world);
});
//=========================================================================================
Player::Player(const sf::Vector2f& pos, b2World& world) :
    MovingObject(Textures::texturesObject().getSprite(PLAYER_T), pos, world,
                 std::make_unique<Animation>(Textures::texturesObject().animationData(PLAYER_D),
                                             AnimationStatus_t::Idle, m_sprite)){
    b2Vec2 position(pos.x, pos.y);

    b2CircleShape circleShape;
    circleShape.m_radius = 0.48 - b2_polygonRadius;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 2.f;
    fixtureDef.friction = 0.f;

    rigidBody(world, position, fixtureDef, b2_dynamicBody);

    setUserData();

    setFixedRotation(true);
}
//=========================================================================================
AnimationStatus_t Player::move() {

    // Player Jump.
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        && m_movement != AnimationStatus_t::Jump && m_movement != AnimationStatus_t::Falling) {
        moveY(0, -DESIREDVEL);
    }
    // Player walk left.
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

        moveX(-DESIREDVEL, 0);
        m_side = opposite(Side_t::LEFT);
    }
    // Player walk right.
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        moveX(DESIREDVEL, 0);
        m_side = opposite(Side_t::RIGHT);
    }
    // Player stands still.
    else {
        moveX(0, 0);
        m_movement = AnimationStatus_t::Idle;
    }
    // The player fires.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {
        m_weapon.shoot(getPos(), *m_body->GetWorld(), m_side);
        m_movement = AnimationStatus_t::Shoot;
    }

    // Changes sprite according to the player situation.
    if (m_body->GetLinearVelocity().y < 0)
        m_movement = AnimationStatus_t::Jump;
    else if (m_body->GetLinearVelocity().y > 0)
        m_movement = AnimationStatus_t::Falling;
    else if (m_body->GetLinearVelocity().x != 0)
        m_movement = AnimationStatus_t::Walk;

    else{
        if (m_movement != AnimationStatus_t::Shoot)
                m_movement = AnimationStatus_t::Idle;
    }
    m_weapon.bulletCheck();

    setAnimationStatus(m_movement);
  
    return m_movement;

}
//=========================================================================================
void Player::drawBullet(sf::RenderWindow& window,sf::Time deltaTime) {
    m_weapon.drawBullet(window,deltaTime);
}
//=========================================================================================
bool Player::isDead()
{
    if (m_hp <= 0)
        return true;
    return false;
}
//=========================================================================================
void Player::startContact(Key* key) {
    ++m_keys;
    key->take();
}
//=========================================================================================
void Player::startContact(Enemy* enemy) {
    m_hp -= enemy->getHit();
    moveY(0, 3);

}
//=========================================================================================