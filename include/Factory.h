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

// A class that implement factory for creating game objects.

class Factory {
public:

    using pFnc = std::shared_ptr<GameObject>(*)(const sf::Vector2f &, b2World &);

    static std::shared_ptr<GameObject> create(const char &, const sf::Vector2f &, b2World &);

    static bool registerObject(const char &, pFnc);

private:
    static auto & getMap(){
        static std::unordered_map<char, pFnc> map;
        return map;
    }
};