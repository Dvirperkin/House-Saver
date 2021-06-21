#include "StaticObject.h"

StaticObject::StaticObject(const sf::Sprite &sprite, const sf::Vector2f &pos, b2World & world, const sf::Vector2f& dimension,const bool sensorStatus, b2BodyType bodyType,
                           std::unique_ptr<Animation> animation)
                : GameObject(sprite, pos, world, dimension, std::move(animation)) {

    b2Vec2 position(pos.x, pos.y);

    b2FixtureDef fixtureDef;
    b2PolygonShape polygonShape;
    polygonShape.SetAsBox(0.5 - b2_polygonRadius, 0.5 - b2_polygonRadius);

    fixtureDef.shape = &polygonShape;
    fixtureDef.density = 2.f;
    fixtureDef.friction = 5.f;
    fixtureDef.isSensor = sensorStatus;
    rigidBody(world, position, fixtureDef, bodyType);
}