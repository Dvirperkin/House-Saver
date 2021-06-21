#include "Player.h"
#include "Enemy.h"
#include "Door.h"
#include "Factory.h"


//=========================================================================================
Player::Player(const sf::Vector2f & pos, b2World & world, const sf::Vector2f & dimension, PlayerStats & playerStats) :
    MovingObject(Textures::texturesObject().getSprite(PLAYER_T), pos, world,dimension,
                 std::make_unique<Animation>(Textures::texturesObject().animationData(PLAYER_D),
                                             AnimationStatus_t::Idle, getSprite(), dimension)),m_weapon(dimension),
                                             m_stats(playerStats){
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
void Player::move() {

    // Player Jump.
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        && m_movement != AnimationStatus_t::Jump && m_movement != AnimationStatus_t::Falling && m_movement != AnimationStatus_t::Shoot) {
        moveY(-DESIRED_VEL);
    }
    // Player walk left.
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

        moveX(-DESIRED_VEL);
        m_side = opposite(Side_t::LEFT);
    }
    // Player walk right.
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        moveX(DESIRED_VEL);
        m_side = opposite(Side_t::RIGHT);
    }
    // Player stands still.
    else {
        moveX(0);
        m_movement = AnimationStatus_t::Idle;
    }

    // The player fires.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {
        m_weapon.shoot(getPos(), *getBody()->GetWorld(), m_side);
        m_movement = AnimationStatus_t::Shoot;
    }

    // Changes sprite according to the player physical status.
    if (getBody()->GetLinearVelocity().y < 0)
        m_movement = AnimationStatus_t::Jump;
    else if (getBody()->GetLinearVelocity().y > 0)
        m_movement = AnimationStatus_t::Falling;
    else if (getBody()->GetLinearVelocity().x != 0)
        m_movement = AnimationStatus_t::Walk;
    else{
        if (m_movement != AnimationStatus_t::Shoot)
            m_movement = AnimationStatus_t::Idle;
    }

    m_weapon.bulletCheck();

    setAnimationStatus(m_movement);

}
//=========================================================================================
sf::Keyboard::Key Player::use() {

    static sf::Clock clock;

    if(clock.getElapsedTime().asSeconds() <= DELAY)
        return sf::Keyboard::Unknown;

    // The player uses an elevator.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        if(m_elevator && m_elevator->destinationUP()) {
            return sf::Keyboard::E;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        if(m_elevator && m_elevator->destinationDown()) {
            return sf::Keyboard::Q;
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
        if (m_door)
            return sf::Keyboard::F;
    }

    clock.restart();
    return sf::Keyboard::Unknown;

}
//=========================================================================================
void Player::drawBullet(sf::RenderWindow& window,sf::Time deltaTime) {
    m_weapon.drawBullet(window,deltaTime);
}
//=========================================================================================
bool Player::isDead(){
    if(m_stats.getLives() <= 0)
        return true;
    return false;
}
//=========================================================================================
void Player::startContact(Key* key) {
    m_stats.keyCollected();
    key->take();
}
//=========================================================================================
void Player::startContact(Enemy* enemy) {
    m_stats.decreaseHP(enemy->getHit());
}
//=========================================================================================
void Player::startContact(Door * door) {
    door->open();
    m_door = door;
}
//=========================================================================================
void Player::startContact(Elevator* elevator) {
    elevator->open();
    m_elevator = elevator;
}
//=========================================================================================
void Player::endContact(Door * door) {
    door->close();
    m_door = nullptr;
}
//=========================================================================================
void Player::endContact(Elevator * elevator) {
    elevator->close();
    m_elevator = nullptr;
}
//=========================================================================================
void Player::draw(sf::RenderWindow & window) {
    GameObject::draw(window);

    m_stats.display(window);
}
//=========================================================================================