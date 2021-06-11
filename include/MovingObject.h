#pragma once

#include "GameObject.h"

class MovingObject : public GameObject {
public:
    MovingObject(const sf::Sprite& sprite, const sf::Vector2f& pos, b2World &,
                 std::unique_ptr<Animation>);

    void moveX(float = 0, float = 0);
    void moveY(float = 0, float = 0);
    virtual void opposite(enum Side_t side);

private:
    enum Side_t m_side = Side_t::RIGHT;
};
