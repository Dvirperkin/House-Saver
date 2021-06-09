#include "StaticObject.h"

StaticObject::StaticObject(const sf::Sprite &sprite, const sf::Vector2f &pos, b2World & world,
                           std::unique_ptr<Animation> animation)
                : GameObject(sprite, pos, std::move(animation)) {

    b2Vec2 position(pos.x, pos.y);

    b2Vec2 dimensions(0.5 - b2_polygonRadius, 0.5 - b2_polygonRadius);

    rigidBody(world, position, dimensions);
}