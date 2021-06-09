#include "House.h"

House::House(const constIterToVecStr& begin,
    const constIterToVecStr& end) : m_world({ 0.0f,100.f }) {

    buildHouse(begin, end);

}
//=============================================================================
void House::buildHouse(const constIterToVecStr& begin,
    const constIterToVecStr& end) {

    m_staticObjects.resize(HOUSE_OBJECT_CAPACITY.second);

    auto i = 0;
    for (auto it = begin; it < begin + HOUSE_OBJECT_CAPACITY.second; ++it, ++i) {
        for (size_t j = 0; j < it->size(); ++j) {
            switch ((*it)[j]) {
            case PLAYER:
                m_player = std::make_unique<Player>(sf::Vector2f(j, i), m_world);
                break;
            case ENEMY: break;
            case WALL: m_staticObjects[i].emplace_back(std::make_unique<Wall>(sf::Vector2f(j, i), m_world)); break;
            case DOOR: break;
            case BOX: break;
            default: m_staticObjects[i].emplace_back(nullptr);
            }
        }
    }
}
//=============================================================================
void House::runHouse(sf::RenderWindow& window) {
    static auto clock = sf::Clock();

    m_world.Step(TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
    m_player->move();
    draw(window);

    auto deltaTime = clock.restart();
    m_player->update(deltaTime);

}
//=============================================================================
void House::draw(sf::RenderWindow& window) {
    for (auto& staticObjectLine : m_staticObjects) {
        for (auto& staticObject : staticObjectLine) {
            if (staticObject)
                staticObject->draw(window);
        }
    }

    m_player->draw(window);
}
//=============================================================================