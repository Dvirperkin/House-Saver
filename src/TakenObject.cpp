#include "TakenObject.h"

TakenObject::TakenObject(const sf::Sprite &sprite , const sf::Vector2f &pos, b2World & world,const bool bulletStatus, b2BodyType bodyType,
                         std::unique_ptr<Animation> animation) : StaticObject(sprite, pos, world, bulletStatus,
                                                                              bodyType, std::move(animation)){
}
