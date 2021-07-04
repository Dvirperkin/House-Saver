#include "HpGift.h"

// Registers the HpGift object to the objects factory.

bool HpGift::m_registerIt = Factory<TakenObject>::registerObject(HP_GIFT, [](const sf::Vector2f& pos,
    b2World& world, const sf::Vector2f& dimension) -> std::shared_ptr<TakenObject> {
        return std::make_shared<HpGift>(pos, world, dimension);
    });
//=============================================================================
HpGift::HpGift(const sf::Vector2f& pos, b2World& world, const sf::Vector2f& dimension) :
            Gift(Textures::texturesObject().getSprite(HP_GIFT_T), pos, world, dimension,
                    std::make_unique<Animation>(Textures::texturesObject().animationData(HP_GIFT_D),
                    AnimationStatus_t::Idle, getSprite(), dimension)) {
}
//=============================================================================