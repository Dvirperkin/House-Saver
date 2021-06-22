#pragma once
#include "TakenObject.h"

class Gift : public TakenObject{
public:
    //----------Constructors\Destructors Section----------
    Gift(const sf::Sprite&, const sf::Vector2f&, b2World&, const sf::Vector2f&, std::unique_ptr<Animation>);

private:
    static bool m_registerIt;

};