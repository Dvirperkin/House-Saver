#include "Key.h"
#include "Factory.h"

// Registers the Key object to the objects factory.

bool Key::m_registerIt = Factory::registerObject('K', [](const sf::Vector2f &pos,
                                                         b2World &world) -> std::shared_ptr<GameObject> {
    return std::make_shared<Key>(pos, world);
});
//=============================================================================
Key::Key(const sf::Vector2f & pos, b2World & world)
    : TakenObject(Textures::texturesObject().getSprite(KEY_T), pos, world, true, b2_staticBody,
                   std::make_unique<Animation>(Textures::texturesObject().animationData(KEY_D),
                                               AnimationStatus_t::Idle, getSprite())){
    setUserData();
}
//=============================================================================