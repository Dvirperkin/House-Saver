#include "Building.h"
#include <ctime>


Building::Building(const buildingDec & building, const buildingsDec& rooms,
                   PlayerStats & playerStats) : m_world({0, 9.8}){
    m_world.SetContactListener(&m_contactListener);

    //Reads building details - Width, Height.
    auto stringStream = std::stringstream();

    stringStream << *building.first;
    if(!(stringStream >> m_width >> m_height))
        throw std::invalid_argument("");

    build(building, rooms, playerStats);
}
//=============================================================================
void Building::build(const buildingDec & building, const buildingsDec & rooms, PlayerStats & playerStats) {
    
    m_staticObjects.resize(m_height);

    //Creates building objects.
    size_t row = 0;

    auto roomIt = rooms.first;

    for (auto it = building.first + 1; it < building.second; ++it, ++row) {
        for (size_t col = 0; col < it->size(); ++col) {
            auto object = (*it)[col];
            switch (object) {
                case PLAYER:
                    m_player = std::make_shared<Player>(sf::Vector2f(col, row), m_world,
                                                        sf::Vector2f(m_width ,m_height), playerStats);
                    break;

                case KNIGHT_ENEMY:
                case SHOOTER_ENEMY:
                    m_enemy.emplace_back(Factory<Enemy>::create(object, sf::Vector2f(col, row), m_world,
                                                                sf::Vector2f(m_width ,m_height)));
                    break;

                case KEY:
                    m_takenObjects.emplace_back(Factory<TakenObject>::create(object, sf::Vector2f(col, row),
                                                                              m_world, sf::Vector2f(m_width, m_height)));
                    ++m_keys;
                    break;

                case GIFT:
                    createGift(sf::Vector2f(col, row));
                    break;

                case ELEVATOR:
                    createElevator(sf::Vector2f(col, row));
                    break;

                case DOOR:
                    if(rooms.first == rooms.second) {
                        m_doors.emplace_back(std::make_shared<Door>(
                                sf::Vector2f(col, row), m_world,
                                sf::Vector2f(m_width, m_height)));
                        break;
                    }

                    createDoor(roomIt, sf::Vector2f(col, row), playerStats);
                    break;

                default:
                    m_staticObjects[row].emplace_back(Factory<StaticObject>::create(
                            object, sf::Vector2f(col, row),
                            m_world, sf::Vector2f(m_width, m_height)));
            }
        }
    }
}
//=============================================================================
void Building::createDoor(std::vector<building>::const_iterator & roomIt,
                          sf::Vector2f pos,
                          PlayerStats & playerStats) {

    m_doors.emplace_back(std::make_shared<Door>(
            pos, m_world,
            sf::Vector2f(m_width, m_height),
            buildRoom(playerStats, {roomIt->cbegin(), roomIt->cend()})));
    ++roomIt;
}
//=============================================================================
void Building::createGift(sf::Vector2f pos)
{
    auto randaom = rand() % 3;
    switch (randaom) {
    case 0:
        m_takenObjects.emplace_back(Factory<TakenObject>::create(HP_GIFT, pos,
            m_world, sf::Vector2f(m_width, m_height)));
        break;
    case 1:
        m_takenObjects.emplace_back(Factory<TakenObject>::create(BULLET_GIFT, pos,
            m_world, sf::Vector2f(m_width, m_height)));
        break;
    case 2:
        m_takenObjects.emplace_back(Factory<TakenObject>::create(LIFE_GIFT, pos,
            m_world, sf::Vector2f(m_width, m_height)));
        break;
    }
    

}
//=============================================================================
std::shared_ptr<Building> Building::buildRoom(PlayerStats & playerStats,
                                              const buildingDec & room,
                                              const buildingsDec & subRooms){

    return std::make_shared<Building>(room, subRooms, playerStats);
}
//=============================================================================
void Building::createElevator(sf::Vector2f pos) {
    static auto index = -1;

    m_elevators.emplace_back(std::make_shared<Elevator>(pos, m_world,
                                                        sf::Vector2f (m_width, m_height)));
    ++index;

    if(index > 0){
        m_elevators[index - 1]->setDestinationDown(m_elevators[index]);
        m_elevators[index]->setDestinationUP(m_elevators[index - 1]);
    }
}
//=============================================================================
BuildingDetails Building::runBuilding(sf::RenderWindow& window) {
    m_details.exit = false;

    if (m_inRoom) {
        auto buildingDetails = m_player->getDoor()->runRoom(window);
        if(buildingDetails.exit)
            m_inRoom = false;

        return m_details;
    }
    m_world.Step(TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
    moveMovingObject();
    action();
    changeView(window);
    checkMissionStatus();
    return m_details;
}
//=============================================================================
void Building::moveMovingObject() {

    if (!m_player->isDead()) {
        m_player->move();
    }
    else
        std::cout << "Player Dead\n";


    for (auto i = 0; i < m_enemy.size() ;i++) {
        if (!m_enemy[i]->isDead())
            m_enemy[i]->move(m_player->getPos());
        else {
            m_enemy.erase(m_enemy.begin() + i);
            --i;
        }
    }
}
//=============================================================================
void Building::action() {
    auto PlayerAction = m_player->use();

    if(PlayerAction == sf::Keyboard::E) {
        if(!m_player->getDoor()->isRoom()) {
            m_details.exit = true;
            return;
        }
        m_inRoom = true;
    }

    else if (PlayerAction == sf::Keyboard::W)
        m_player->setBodyPos(m_player->getElevator()->getElevatorDestinationUp());

    else if (PlayerAction == sf::Keyboard::S)
        m_player->setBodyPos(m_player->getElevator()->getElevatorDestinationDown());

}
//=============================================================================
void Building::changeView(sf::RenderWindow & window) {
    auto view = window.getView();
    view.setSize(float(WINDOW_SIZE.first / m_width) * 12, (float(WINDOW_SIZE.second / m_height) * 8));

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
void Building::checkMissionStatus()
{
    if (m_enemy.size() == 0)
        m_details.m_killAllEnemy = true;    
    if (m_keys == 0)
        m_details.m_allKeyCollected = true;
    for (auto& door : m_doors) {
        if (!door->roomMissionComplete())
            return;
    }
    m_details.m_missionComplete = true;
}
//=============================================================================
void Building::draw(sf::RenderWindow& window, const sf::Time & deltaTime) {
    if (m_inRoom) {
        m_player->getDoor()->drawRoom(window, deltaTime);
        return;
    }
    for (auto& elevator : m_elevators) {
        elevator->draw(window);
        elevator->update(deltaTime, sf::Vector2f(m_width,m_height));
    }
    for (auto& doors : m_doors) {
        doors->draw(window);
        doors->update(deltaTime, sf::Vector2f(m_width, m_height));
    }
    for (size_t i = 0; i < m_takenObjects.size(); ++i) {
        if (!m_takenObjects[i]->isTaken()) {
            m_takenObjects[i]->draw(window);
            m_takenObjects[i]->update(deltaTime, sf::Vector2f(m_width, m_height));
        }
        else {
            if (m_takenObjects[i]->getBodyType() == KEY)
                --m_keys;
            m_takenObjects.erase(m_takenObjects.begin() + i);
            
        }

    }
    for (auto & staticObjectLine : m_staticObjects) {
        for (auto& staticObject : staticObjectLine) {
            if (staticObject) {
                staticObject->draw(window);
                staticObject->update(deltaTime, sf::Vector2f(m_width, m_height));
            }
        }
    }

    for (auto& enemy : m_enemy) {
        enemy->draw(window, deltaTime);
        enemy->update(deltaTime, sf::Vector2f(m_width, m_height));
    }
    m_player->draw(window, deltaTime);
    m_player->update(deltaTime, sf::Vector2f(m_width, m_height));
}
//=============================================================================