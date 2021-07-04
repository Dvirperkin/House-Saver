#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "box2d/box2d.h"
#include "Animation.h"
#include "Textures.h"
#include "Sounds.h"

// An abstract class that implements a game object.

class GameObject {
public:
    //----------Constructors\Destructors Section----------
    GameObject(const sf::Sprite &, const sf::Vector2f &, b2World &, const sf::Vector2f &,
               std::unique_ptr<Animation> = nullptr);

    virtual ~GameObject();

    //----------Functions Section----------
    void draw(sf::RenderWindow &window) { window.draw(m_sprite); }

    // Creates rigid body for the object in the physical world.
    void rigidBody(b2World &, const b2Vec2 &,
                   enum Shape_t, float, float, float, float, float, bool,
                   const b2BodyType = b2_staticBody);

    // Update animation.
    void update(sf::Time deltaTime, const sf::Vector2f &);

    void setPos(const sf::Vector2f &);

    sf::Vector2f getPos() const { return m_sprite.getPosition(); }

    sf::FloatRect getGlobalBounds() const { return m_sprite.getGlobalBounds(); }



    //----------Physical Body Information Section----------

    //Sets Section

    void setRotation();

    void setBodyPos(b2Vec2 pos) { m_body->SetTransform(pos, m_body->GetAngle()); }

    void setUserData() { m_body->SetUserData(this); }

    void setFixedRotation(bool status) { m_body->SetFixedRotation(status); };

    void setAnimationStatus(enum AnimationStatus_t status) { m_animation->setStatus(status); }

    //Gets Section

    b2Vec2 getBodyPos() const { return m_body->GetPosition(); }

    float getBodyMass() const { return m_body->GetMass(); }

    b2Vec2 getBodyLinearVelocity() const { return m_body->GetLinearVelocity(); };

    virtual Objects_t getBodyType() const = 0;



protected:
    b2Body * getBody() const { return m_body; }

    sf::Sprite & getSprite() { return m_sprite; }

private:
    b2Body *m_body;
    sf::Sprite m_sprite;
    b2World & m_world;
    sf::Vector2f m_pos;
    std::unique_ptr<Animation> m_animation;
};