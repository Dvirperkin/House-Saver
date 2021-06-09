#include "GameObject.h"

GameObject::GameObject(const sf::Sprite & sprite, const sf::Vector2f & pos,
                       std::unique_ptr<Animation> animation) :
                       m_body(nullptr), m_sprite(sprite), m_pos(pos){

    m_sprite.setScale(HOUSE_SIZE.first / (m_sprite.getGlobalBounds().width * HOUSE_OBJECT_CAPACITY.first),
                      HOUSE_SIZE.second / (m_sprite.getGlobalBounds().height * HOUSE_OBJECT_CAPACITY.second));

    m_sprite.setPosition(m_pos.x * HOUSE_SIZE.first / HOUSE_OBJECT_CAPACITY.first,
                         m_pos.y * HOUSE_SIZE.second / HOUSE_OBJECT_CAPACITY.second);

    m_animation = std::move(animation);
}
//=============================================================================
void GameObject::setPos(const sf::Vector2f & pos) {
    m_sprite.setPosition(pos);
    m_pos = pos;
}
//=============================================================================
void GameObject::rigidBody(b2World & world, const b2Vec2 & pos, const b2Vec2 & dimensions,
                           const b2BodyType & bodyType) {
    b2BodyDef bodyDef;
    bodyDef.type = bodyType;
    bodyDef.position.Set(pos.x, pos.y);
    m_body = world.CreateBody(&bodyDef);

    b2PolygonShape polygonShape;
    polygonShape.SetAsBox(dimensions.x, dimensions.y);

    if(bodyType == b2_staticBody)
        m_body->CreateFixture(&polygonShape, 0.0f);

    else {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &polygonShape;
        fixtureDef.density = 1.f;
        fixtureDef.friction = 0.3f;

        m_body->CreateFixture(&fixtureDef);
    }
}
//=============================================================================
void GameObject::setRotation() {
    m_sprite.rotate(m_body->GetAngle());
}
//=============================================================================
void GameObject::update(sf::Time deltaTime) {
    if(m_animation)
        m_animation->update(deltaTime);
}
