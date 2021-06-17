#pragma once

#include <SFML/Graphics.hpp>

#include "box2d/box2d.h"
#include "Animation.h"
#include "Textures.h"

class GameObject {
public:
    //----------Constructors\Destructors Section----------
    GameObject(const sf::Sprite &, const sf::Vector2f &, b2World &, std::unique_ptr<Animation> = nullptr);
    virtual ~GameObject() {m_world.DestroyBody(m_body);};

    void draw(sf::RenderWindow & window){window.draw(m_sprite);}

    void rigidBody(b2World &, const b2Vec2 &,const b2FixtureDef &, const b2BodyType = b2_staticBody);

    void update(sf::Time deltaTime);

    sf::Vector2f getPos() const {return m_sprite.getPosition();}
    sf::FloatRect getGlobalBounds() const {return m_sprite.getGlobalBounds();}

    b2Vec2 getBodyPos() const {return m_body->GetPosition();}

    float getBodyMass() const {return m_body->GetMass();}

    b2Vec2 getBodyLinearVelocity() const {return m_body->GetLinearVelocity();};

    virtual Objects_t getBodyType() const = 0;

    void setRotation();

    void setPos(const sf::Vector2f &);

    void setUserData() {m_body->SetUserData(this);}

    void setFixedRotation(bool status) {m_body->SetFixedRotation(status);};

    void setAnimationStatus(enum AnimationStatus_t status) {m_animation->setStatus(status);}


protected:
    b2Body * m_body;
    sf::Sprite m_sprite;

private:
    b2World & m_world;
    sf::Vector2f m_pos;
    std::unique_ptr<Animation> m_animation;
};