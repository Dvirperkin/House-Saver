#include "Player.h"

//=========================================================================================
Player::Player(const sf::Vector2f & pos, b2World & world, const sf::Vector2f & dimension, PlayerStats & playerStats) :
    MovingObject(Textures::texturesObject().getSprite(PLAYER_T), pos, world,dimension,
                 std::make_unique<Animation>(Textures::texturesObject().animationData(PLAYER_D),
                                             AnimationStatus_t::Idle, getSprite(), dimension)), m_weapon(dimension, -2),
                                             m_stats(playerStats) {
    b2Vec2 position(pos.x, pos.y);

    rigidBody(world, position, CIRCLE_SHAPE, MOVING_OBJECT_PHYSICAL_SIZE,
              2.f, 0.f, -2, 0, false, b2_dynamicBody);

    setUserData();

    setFixedRotation(true);
}
//=========================================================================================
void Player::move() {

    // Player Jump.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
        && m_movement != AnimationStatus_t::Jump && m_movement != AnimationStatus_t::Falling && m_movement != AnimationStatus_t::Shoot) {
        Sounds::soundObject().playSound(Sounds_t::PLAYER_JUMP_SOUND);
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
        Sounds::soundObject().playSound(Sounds_t::SHOOT_SOUND);
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(m_elevator && m_elevator->destinationUP()) {
            return sf::Keyboard::W;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if(m_elevator && m_elevator->destinationDown()) {
            return sf::Keyboard::S;
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        if (m_door) {
            clock.restart();
            return sf::Keyboard::E;
        }
    }

    clock.restart();
    return sf::Keyboard::Unknown;

}
//=========================================================================================
bool Player::isDead(){
    if (m_stats.getLives() <= 0) {
        Sounds::soundObject().playSound(DEATH_SOUND);
        return true;
    }
    return false;
}
//=========================================================================================
void Player::startContact(Key * key) {
    Sounds::soundObject().playSound(GIFT_SOUND);
    m_stats.keyCollected();
    key->take();
}
//=========================================================================================
void Player::startContact(Enemy * enemy) {
    if(enemy->getMovement() == AnimationStatus_t::Death)
        return;

    m_stats.decreaseHP(enemy->getHit());
}
//=========================================================================================
void Player::startContact(Door * door) {
    Sounds::soundObject().playSound(DOOR_SOUND);
    door->open();
    m_door = door;
}
//=========================================================================================
void Player::startContact(Elevator * elevator) {
    Sounds::soundObject().playSound(ELEVATOR_SOUND);
    elevator->open();
    m_elevator = elevator;
}
//=========================================================================================
void Player::startContact(HpGift * gift){
    Sounds::soundObject().playSound(GIFT_SOUND);
    m_stats.increaseHP();
    gift->take();
}
//=========================================================================================
void Player::startContact(BulletGift * gift){
    Sounds::soundObject().playSound(GIFT_SOUND);
    m_stats.addScore(SCORE_INCREASE);
    m_weapon.increaseBulletDamage();
    gift->take();
}
//=========================================================================================
void Player::startContact(Bullet* bullet) {
    Sounds::soundObject().playSound(PLAYER_HURT_SOUND);
    m_stats.decreaseHP(bullet->getHit());
    bullet->hit();
}
//=========================================================================================
void Player::startContact(LifeGift * gift){
    Sounds::soundObject().playSound(GIFT_SOUND);
    m_stats.addScore(SCORE_INCREASE);
    m_stats.increaseLife();
    gift->take();
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
void Player::draw(sf::RenderWindow & window, sf::Time deltaTime) {
    MovingObject::draw(window,deltaTime);
    m_weapon.drawBullet(window, deltaTime);
    m_stats.display(window);
}
//=========================================================================================