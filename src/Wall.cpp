#include "Wall.h"

Wall::Wall(const sf::Vector2f &pos, b2World &world) :
            StaticObject(Textures::texturesObject().getSprite(WALL_T), pos, world){
}
