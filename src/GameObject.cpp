#include "GameObject.h"

GameObject::GameObject(const sf::Sprite & sprite, const sf::Vector2f & pos, b2World & world,
                       std::unique_ptr<Animation> animation) :
                       m_body(nullptr), m_sprite(sprite), m_world(world), m_pos(pos){

    m_sprite.setScale(WINDOW_SIZE.first / (m_sprite.getGlobalBounds().width * HOUSE_OBJECT_CAPACITY.first),
                      WINDOW_SIZE.second / (m_sprite.getGlobalBounds().height * HOUSE_OBJECT_CAPACITY.second));

    m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);

    m_sprite.setPosition(m_pos.x * WINDOW_SIZE.first / HOUSE_OBJECT_CAPACITY.first + m_sprite.getGlobalBounds().width / 2,
                         m_pos.y * WINDOW_SIZE.second / HOUSE_OBJECT_CAPACITY.second + m_sprite.getGlobalBounds().height / 2);

    m_animation = std::move(animation);
}
//=============================================================================
GameObject::~GameObject() {
    m_body->SetUserData(nullptr);
    m_world.DestroyBody(m_body);
}
//=============================================================================
void GameObject::setPos(const sf::Vector2f & pos) {
    m_sprite.setPosition(pos);
    m_pos = pos;
}
//=============================================================================
void GameObject::rigidBody(b2World & world, const b2Vec2 & pos,
                            const b2FixtureDef & fixtureDef, const b2BodyType bodyType) {
    b2BodyDef bodyDef;
    bodyDef.type = bodyType;
    bodyDef.position.Set(pos.x, pos.y);
    m_body = world.CreateBody(&bodyDef);
    m_body->CreateFixture(&fixtureDef);

}
//=============================================================================
void GameObject::setRotation() {
    m_sprite.rotate(m_body->GetAngle());
}
//=============================================================================
void GameObject::update(sf::Time deltaTime) {
    if(m_animation)
        m_animation->update(deltaTime);

    auto position = getBodyPos();
    position.x *= WINDOW_SIZE.first / HOUSE_OBJECT_CAPACITY.first;
    position.y *= WINDOW_SIZE.second / HOUSE_OBJECT_CAPACITY.second;
    position.x += m_sprite.getGlobalBounds().width / 2;
    position.y += m_sprite.getGlobalBounds().height / 2;
    setPos({ position.x, position.y});
}
