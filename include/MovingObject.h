#pragma once

#include "GameObject.h"

// An abstract class that represents a moving object.

class MovingObject : public GameObject {
public:
    //----------Constructors\Destructors Section----------
    MovingObject(const sf::Sprite &, const sf::Vector2f &, b2World &, const sf::Vector2f &,
                 std::unique_ptr<Animation> = nullptr);

    //----------Functions Section----------
    virtual void draw(sf::RenderWindow&, sf::Time);
    void moveX(float = 0);
    void moveY(float = 0);
    virtual Side_t opposite(enum Side_t side);

private:
    enum Side_t m_side = Side_t::RIGHT;
};
