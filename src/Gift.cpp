#include "Gift.h"

//=============================================================================
Gift::Gift(const sf::Sprite& sprite, const sf::Vector2f& pos, b2World& world, const sf::Vector2f& dimension, std::unique_ptr<Animation> animation)
    : TakenObject(sprite, pos, world, dimension, true, b2_staticBody, std::move(animation)) {

    setUserData();
}
//=============================================================================