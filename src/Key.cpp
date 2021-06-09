#include "Key.h"
Key::Key(const sf::Vector2f & pos, b2World & world)
    : StaticObject(Textures::texturesObject().getSprite(KEY_T), pos, world,
                   std::make_unique<Animation>(Textures::texturesObject().animationData(KEY_D),
                                               AnimationStatus_t::Idle, m_sprite))
{
}