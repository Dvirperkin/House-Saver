#include "BulletGift.h"
#include "Factory.h"
bool BulletGift::m_registerIt = Factory<TakenObject>::registerObject(BULLET_GIFT, [](const sf::Vector2f& pos,
    b2World& world, const sf::Vector2f& dimension) -> std::shared_ptr<TakenObject> {

        return std::make_shared<BulletGift>(pos, world, dimension);
    });
//=============================================================================
BulletGift::BulletGift(const sf::Vector2f& pos, b2World& world, const sf::Vector2f& dimension):
    Gift(Textures::texturesObject().getSprite(BULLET_GIFT_T), pos, world, dimension,
        std::make_unique<Animation>(Textures::texturesObject().animationData(BULLET_GIFT_D),
            AnimationStatus_t::Idle, getSprite(), dimension)) {
}