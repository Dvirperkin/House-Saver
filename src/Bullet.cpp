#include "Bullet.h"

Bullet::Bullet(const sf::Vector2f & pos, b2World & world) :
        MovingObject(Textures::texturesObject().getSprite(BULLET_T), pos, world,
                     std::make_unique<Animation>(Textures::texturesObject().animationData(BULLET_D),
                                                 AnimationStatus_t::Idle, m_sprite)){


}
