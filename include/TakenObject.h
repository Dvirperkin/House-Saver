#pragma once

#include "StaticObject.h"


class TakenObject : public StaticObject{
public:
    TakenObject(const sf::Sprite &sprite , const sf::Vector2f &pos, b2World & world,const bool, b2BodyType,
                std::unique_ptr<Animation> animation);

    bool isTaken() const {return m_taken;}
    void take() {m_taken = true;}

private:
    bool m_taken = false;
};