#pragma once

#include <memory>

#include "Macros.h"
#include "Player.h"
#include "Box.h"
#include "Key.h"
#include "Wall.h"
#include "Bullet.h"
#include "Elevator.h"
#include "KnightEnemy.h"
#include "BulletGift.h"
#include "HpGift.h"
#include "LifeGift.h"

// A class that implement factory for creating game objects.

template <typename T>
class Factory {
public:

    using pFnc = std::shared_ptr<T>(*)(const sf::Vector2f &, b2World &, const sf::Vector2f&);

    static std::shared_ptr<T> create(const char &, const sf::Vector2f &, b2World &, const sf::Vector2f&);

    static bool registerObject(const char &, pFnc);

private:
    static auto & getMap(){
        static std::unordered_map<char, pFnc> map;
        return map;
    }
};
//=============================================================================
template<typename T>
std::shared_ptr<T> Factory<T>::create(const char & name, const sf::Vector2f & pos, b2World & world,
                                      const sf::Vector2f & dimension) {
    // Checks if the request object is registered to the factory.
    auto it = Factory::getMap().find(name);
    if(it == Factory::getMap().end())
        return nullptr;
    return it->second(pos, world, dimension);
}

//=============================================================================
template<typename T>
bool Factory<T>::registerObject(const char & name, Factory::pFnc func) {
    // Registers object to the factory.
    Factory::getMap().emplace(name, func);

    return true;
}
//=============================================================================