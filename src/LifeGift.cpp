#include "LifeGift.h"

// Registers the LifeGift object to the objects factory.

bool LifeGift::m_registerIt = Factory<TakenObject>::registerObject(LIFE_GIFT, [](const sf::Vector2f& pos,
    b2World& world, const sf::Vector2f& dimension) -> std::shared_ptr<TakenObject> {
        return std::make_shared<LifeGift>(pos, world, dimension);
});
//=============================================================================
LifeGift::LifeGift(const sf::Vector2f& pos, b2World& world, const sf::Vector2f& dimension) :
    Gift(Textures::texturesObject().getSprite(LIFE_GIFT_T), pos, world, dimension,
        std::make_unique<Animation>(Textures::texturesObject().animationData(LIFE_GIFT_D),
            AnimationStatus_t::Idle, getSprite(), dimension)) {
}
//=============================================================================