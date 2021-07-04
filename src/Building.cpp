#include "Building.h"

Building::Building(const buildingDec & building, const buildingsDec& rooms,
                   PlayerStats & playerStats, enum BuildingBackGround_t backGround) : m_world({0, 9.8}),
                                                                                      m_backGround(Textures::texturesObject().getHouseSprite(backGround)){
    m_world.SetContactListener(&m_contactListener);

    // Reads building details - Width, Height.
    auto stringStream = std::stringstream();

    stringStream << *building.first;
    if(!(stringStream >> m_width >> m_height))
        throw std::invalid_argument("Width and height of the building must be a positive number.");

    m_backGround.scale(WINDOW_SIZE.first / m_backGround.getGlobalBounds().width,
                       WINDOW_SIZE.second / m_backGround.getGlobalBounds().height);

    build(building, rooms, playerStats);
}
//=============================================================================
void Building::build(const buildingDec & building, const buildingsDec & rooms, PlayerStats & playerStats) {
    
    m_staticObjects.resize(m_height);

    size_t row = 0;

    // Indicates the next room to build.
    auto roomIt = rooms.first;

    // Creates building objects.
    for (auto it = building.first + 1; it < building.second; ++it, ++row) {
        for (size_t col = 0; col < it->size(); ++col) {
            auto object = (*it)[col];
            switch (object) {
                case PLAYER:
                    m_player = std::make_shared<Player>(sf::Vector2f(col, row), m_world,
                                                        sf::Vector2f(m_width ,m_height), playerStats);
                    break;

                case THIEF_ENEMY:
                case SHOOTER_ENEMY:
                    m_enemies.emplace_back(Factory<Enemy>::create(object, sf::Vector2f(col, row), m_world,
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
                    // Condition for the door in room that return to the house.
                    if(rooms.first == rooms.second) {
                        m_doors.emplace_back(std::make_shared<Door>(
                                sf::Vector2f(col, row), m_world,
                                sf::Vector2f(m_width, m_height)));
                        break;
                    }

                    createDoor(roomIt, sf::Vector2f(col, row), playerStats);
                    break;

                default:
                    auto staticObject = Factory<StaticObject>::create(
                            object, sf::Vector2f(col, row),
                            m_world, sf::Vector2f(m_width, m_height));

                    if(!staticObject && object != ' ')
                        throw std::invalid_argument("Invalid character was entered in Houses.txt file.");

                    m_staticObjects[row].emplace_back(staticObject);
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
void Building::createGift(sf::Vector2f pos){

    auto random = rand() % 3;
    switch (random) {
    case GIFT_HP:
        m_takenObjects.emplace_back(Factory<TakenObject>::create(HP_GIFT, pos,
            m_world, sf::Vector2f(m_width, m_height)));
        break;
    case GIFT_BULLET:
        m_takenObjects.emplace_back(Factory<TakenObject>::create(BULLET_GIFT, pos,
            m_world, sf::Vector2f(m_width, m_height)));
        break;
    case GIFT_LIFE:
        m_takenObjects.emplace_back(Factory<TakenObject>::create(LIFE_GIFT, pos,
            m_world, sf::Vector2f(m_width, m_height)));
        break;
    }
}
//=============================================================================
std::shared_ptr<Building> Building::buildRoom(PlayerStats & playerStats,
                                              const buildingDec & room,
                                              const buildingsDec & subRooms){

    return std::make_shared<Building>(room, subRooms, playerStats, Room);
}
//=============================================================================
void Building::createElevator(sf::Vector2f pos) {
    auto index = m_elevators.size() - 1;

    m_elevators.emplace_back(std::make_shared<Elevator>(pos, m_world,
                                                        sf::Vector2f (m_width, m_height)));
    ++index;

    // Connects the elevator to the elevator above.
    if(index > 0){
        m_elevators[index - 1]->setDestinationDown(m_elevators[index]);
        m_elevators[index]->setDestinationUP(m_elevators[index - 1]);
    }
}
//=============================================================================
BuildingDetails Building::runBuilding(sf::RenderWindow& window) {
    // Initialize room exit status to enter again.
    m_details.exit = false;

    // Checks if the player is in room and if it is display the room.
    if (m_inRoom) {
        auto buildingDetails = m_player->getDoor()->runRoom(window);

        // Checks if the player ask to exit from the building.
        if(buildingDetails.exit)
            m_inRoom = false;

        // Updates the general GameOver detail to indicates that the player is died.
        m_details.m_GameOver = buildingDetails.m_GameOver;

        return m_details;
    }

    m_world.Step(TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
    moveMovingObject(window);
    action();
    changeView(window);
    checkMissionStatus();
    return m_details;
}
//=============================================================================
void Building::moveMovingObject(sf::RenderWindow & window) {

    if (!m_player->isDead()) {
        m_player->move();
    }
    else {   
        m_details.m_GameOver = true;
        GameOver(window);
    }

    for (auto i = 0; i < m_enemies.size() ; i++) {
        if (!m_enemies[i]->isDead())
            m_enemies[i]->move(m_player->getPos());
        else {
            m_enemies[i]->setAnimationStatus(AnimationStatus_t::Death);
            m_enemies.erase(m_enemies.begin() + i);
            --i;
        }
    }
}
//=============================================================================
void Building::action() {

    // Returns the requested action of the player.
    auto PlayerAction = m_player->use();

    if(PlayerAction == sf::Keyboard::E) {
        // Condition for an exit door.
        if(!m_player->getDoor()->isRoom()) {
            m_details.exit = true;
            return;
        }
        m_inRoom = true;
    }

    else if (PlayerAction == sf::Keyboard::W) {
        auto pos = m_player->getElevator()->getElevatorDestinationUp();
        if(pos.has_value())
            m_player->setBodyPos(pos.value());
    }

    else if (PlayerAction == sf::Keyboard::S) {
        auto pos = m_player->getElevator()->getElevatorDestinationDown();
        if(pos.has_value())
            m_player->setBodyPos(pos.value());
    }

}
//=============================================================================
void Building::changeView(sf::RenderWindow & window) {
    auto view = window.getView();
    auto position = sf::Vector2f();

    auto viewSize = sf::Vector2f(float(WINDOW_SIZE.first / m_width) * WIDTH_VIEW,
                                 (float(WINDOW_SIZE.second / m_height) * HEIGHT_VIEW));

    // For small buildings.
    if(m_width < WIDTH_VIEW)
        viewSize.x = m_width;
    if(m_height < HEIGHT_VIEW)
        viewSize.y = m_height;

    view.setSize(viewSize);

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
void Building::checkMissionStatus(){
    if (m_enemies.size() == 0)
        m_details.m_killAllEnemy = true;    
    if (m_keys == 0)
        m_details.m_allKeyCollected = true;
    for (auto& door : m_doors) {
        if (!door->isRoomMissionComplete())
            return;
    }

    m_details.m_allRoomComplete = true;
}
//=============================================================================
void Building::draw(sf::RenderWindow& window, const sf::Time & deltaTime) {

    // Checks if the player is in room and if it is draw the room.
    if (m_inRoom) {
        m_player->getDoor()->drawRoom(window, deltaTime);
        return;
    }

    window.draw(m_backGround);

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
            // Checks if the current object was taken.
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

    for (auto& enemy : m_enemies) {
        enemy->draw(window, deltaTime);
        enemy->update(deltaTime, sf::Vector2f(m_width, m_height));
    }

    m_player->draw(window, deltaTime);
    m_player->update(deltaTime, sf::Vector2f(m_width, m_height));
}
//=============================================================================
void Building::GameOver(sf::RenderWindow & window) {

    // Display player death animation.
    auto clock = sf::Clock();
    auto animationTime = sf::Clock();
    m_player->setAnimationStatus(AnimationStatus_t::Death);

    while (animationTime.getElapsedTime().asSeconds() <= DEATH_ANIMATION_TIME) {
        window.clear();
        draw(window,clock.restart());
        window.display();
    }
}
//=============================================================================