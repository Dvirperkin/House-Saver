#include "Factory.h"

std::shared_ptr<GameObject> Factory::create(const char & name, const sf::Vector2f & pos, b2World & world) {

    // Checks if the request object is registered to the factory.
    auto it = Factory::getMap().find(name);
    if(it == Factory::getMap().end())
        return nullptr;
    return it->second(pos, world);
}
//=============================================================================
bool Factory::registerObject(const char & name, Factory::pFnc func) {

    // Registers object to the factory.
    Factory::getMap().emplace(name, func);

    return true;
}
//=============================================================================