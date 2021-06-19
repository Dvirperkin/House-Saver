#include "Building.h"

Building::Building() : m_world({0, 9.8}){
    m_world.SetContactListener(&m_contactListener);
}
//=============================================================================
void Building::build(const buildingDec & building) {

    //Reads building details - Width, Height.
    auto stringStream = std::stringstream();

    stringStream << *building.first;
    if(!(stringStream >> m_width >> m_height))
        throw std::invalid_argument("");

    m_staticObjects.resize(m_height);

    //Creates building objects.
    auto i = 0;
    for (auto it = building.first + 1; it < building.second; ++it, ++i) {
        for (size_t j = 0; j < it->size(); ++j) {
            switch ((*it)[j]) {
                case PLAYER:
                    m_player = std::static_pointer_cast<Player>(Factory::create(PLAYER, sf::Vector2f(j, i), m_world));
                    break;

                case ENEMY:
                    m_enemy.emplace_back(std::static_pointer_cast<Enemy>(Factory::create((*it)[j], sf::Vector2f(j, i), m_world)));
                    break;

                case KEY:
                    m_takenObjects.emplace_back(std::static_pointer_cast<TakenObject>(Factory::create((*it)[j], sf::Vector2f(j, i), m_world)));
                    break;

                case ELEVATOR:
                    createElevator(sf::Vector2f(j, i));
                    break;

                default:
                    m_staticObjects[i].emplace_back(std::static_pointer_cast<StaticObject>(Factory::create((*it)[j], sf::Vector2f(j, i), m_world)));
            }
        }
    }
}
//=============================================================================
void Building::createElevator(sf::Vector2f pos) {
    static auto index = -1;

    m_elevators.emplace_back(std::static_pointer_cast<Elevator>(Factory::create(ELEVATOR, pos, m_world)));
    ++index;

    if(index > 0){
        m_elevators[index - 1]->setDestinationDown(m_elevators[index]);
        m_elevators[index]->setDestinationUP(m_elevators[index - 1]);
    }
}
//=============================================================================
void Building::runBuilding(sf::RenderWindow& window) {

    m_world.Step(TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
    moveMovingObject();
    changeView(window);
}
//=============================================================================
void Building::moveMovingObject() {

    if (!m_player->isDead()) {
        m_player->move();
        m_player->use();
    }
    else
        std::cout << "Player Dead\n";


    for (auto i = 0; i < m_enemy.size() ;i++) {
        if (!m_enemy[i]->isDead())
            m_enemy[i]->move();
        else {
            m_enemy.erase(m_enemy.begin() + i);
            --i;
        }
    }
}
//=============================================================================
void Building::changeView(sf::RenderWindow & window) {
    auto view = window.getView();
    view.setSize((WINDOW_SIZE.first / m_width) * 12, (WINDOW_SIZE.second / m_height) * 8);

    auto position = sf::Vector2f();

    if(m_player->getPos().x > WINDOW_SIZE.first - view.getSize().x / 2)
        position.x = WINDOW_SIZE.first - view.getSize().x / 2;
    else if(m_player->getPos().x < view.getSize().x / 2)
        position.x = view.getSize().x / 2;
    else
        position.x = m_player->getPos().x;

    if(m_player->getPos().y > WINDOW_SIZE.second - view.getSize().y / 2)
        position.y = WINDOW_SIZE.second - view.getSize().y / 2;
    else if(m_player->getPos().y < view.getSize().y / 2)
        position.y = view.getSize().y / 2;
    else
        position.y = m_player->getPos().y;

    view.setCenter(position);
    window.setView(view);
}
//=============================================================================
void Building::draw(sf::RenderWindow& window, const sf::Time & deltaTime) {
    for (size_t i = 0; i < m_takenObjects.size(); ++i) {
        if (!m_takenObjects[i]->isTaken()) {
            m_takenObjects[i]->draw(window);
            m_takenObjects[i]->update(deltaTime);
        }
        else
            m_takenObjects.erase(m_takenObjects.begin() + i);
    }
    for (auto & staticObjectLine : m_staticObjects) {
        for (auto& staticObject : staticObjectLine) {
            if (staticObject) {
                staticObject->draw(window);
                staticObject->update(deltaTime);
            }
        }
    }

    for(auto & elevator : m_elevators){
        elevator->draw(window);
        elevator->update(deltaTime);
    }

    for (auto& enemy : m_enemy) {
        enemy->draw(window);
        enemy->update(deltaTime);
    }
    m_player->draw(window);
    m_player->update(deltaTime);
    m_player->drawBullet(window, deltaTime);
}
//=============================================================================