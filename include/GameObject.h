#pragma once

#include <SFML/Graphics.hpp>

#include "box2d/box2d.h"
#include "Animation.h"
#include "Textures.h"

class GameObject {
public:
    //----------Constructors\Destructors Section----------
    GameObject(const sf::Sprite &, const sf::Vector2f &, std::unique_ptr<Animation> = nullptr);

    void draw(sf::RenderWindow & window){window.draw(m_sprite);}

    void rigidBody(b2World &, const b2Vec2 &,  const b2Vec2 &, const b2BodyType & = b2_staticBody);

    void update(sf::Time deltaTime);

    sf::Vector2f getPos() const {return m_pos;}

    b2Vec2 getBodyPos() const {return m_body->GetPosition();}

    float getBodyMass() const {return m_body->GetMass();}

    b2Vec2 getBodyLinearVelocity() const {return m_body->GetLinearVelocity();};

    void setRotation();

    void setPos(const sf::Vector2f &);

    void setFixedRotation(bool status) {m_body->SetFixedRotation(status);};

    void setAnimationStatus(enum AnimationStatus_t status) {m_animation->setStatus(status);}


protected:
    b2Body * m_body;
    sf::Sprite m_sprite;

private:

    sf::Vector2f m_pos;
    std::unique_ptr<Animation> m_animation;
};