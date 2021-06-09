#include "House.h"

House::House(const constIterToVecStr& begin,
    const constIterToVecStr& end) : m_world({ 0.0f, 100.f }) {
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
            case KEY: m_staticObjects[i].emplace_back(std::make_unique<Key>(sf::Vector2f(j, i), m_world)); break;
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

    m_world.Step(TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
    auto movement = m_player->move();
    changeView(window);

}
//=============================================================================
void House::changeView(sf::RenderWindow & window) {
    auto view = window.getView();
    view.setSize(600,400);

    auto position = sf::Vector2f();

    if(m_player->getPos().x > HOUSE_SIZE.first - view.getSize().x/2)
        position.x = HOUSE_SIZE.first - view.getSize().x/2;
    else if(m_player->getPos().x < view.getSize().x / 2)
        position.x = view.getSize().x / 2;
    else
        position.x = m_player->getPos().x;

    if(m_player->getPos().y > HOUSE_SIZE.second - view.getSize().y/2)
        position.y = HOUSE_SIZE.second - view.getSize().y/2;
    else if(m_player->getPos().y < view.getSize().y / 2)
        position.y = view.getSize().y / 2;
    else
        position.y = m_player->getPos().y;

    view.setCenter(position);
    window.setView(view);
}
//=============================================================================
void House::draw(sf::RenderWindow& window, const sf::Time & deltaTime) {
    for (auto& staticObjectLine : m_staticObjects) {
        for (auto& staticObject : staticObjectLine) {
            if (staticObject) {
                staticObject->draw(window);
                staticObject->update(deltaTime);
            }
        }
    }

    m_player->draw(window);
    m_player->update(deltaTime);
}
//=============================================================================