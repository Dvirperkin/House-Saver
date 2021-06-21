#include "Key.h"
#include "Factory.h"

// Registers the Key object to the objects factory.

bool Key::m_registerIt = Factory<TakenObject>::registerObject(KEY, [](const sf::Vector2f &pos,
                                                         b2World &world, const sf::Vector2f& dimension) -> std::shared_ptr<TakenObject> {
    return std::make_shared<Key>(pos, world, dimension);
});
//=============================================================================
Key::Key(const sf::Vector2f & pos, b2World & world, const sf::Vector2f& dimension)
    : TakenObject(Textures::texturesObject().getSprite(KEY_T), pos, world, dimension, true, b2_staticBody,
                   std::make_unique<Animation>(Textures::texturesObject().animationData(KEY_D),
                                               AnimationStatus_t::Idle, getSprite(), dimension)){
    setUserData();
}
//=============================================================================