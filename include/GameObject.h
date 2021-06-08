#pragma once

#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"
#include "Textures.h"

class GameObject {
public:
    //----------Constructors\Destructors Section----------
    GameObject(const sf::Sprite &, const sf::Vector2f &);

    void draw(sf::RenderWindow & window){window.draw(m_sprite);};

    sf::Vector2f getPos() const {return m_pos;};

    void setPos(const sf::Vector2f &);

    void rigidBody(b2World &, const b2Vec2 &,  const b2Vec2 &, const b2BodyType & = b2_staticBody);

protected:
    b2Body * m_body;
    sf::Sprite m_sprite;

private:
    sf::Vector2f m_pos;

};