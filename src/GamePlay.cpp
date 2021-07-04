#include "GamePlay.h"

GamePlay::GamePlay(int pos) : Command(pos, "New Game"),
                              m_currHouse(0), m_houseFile(HOUSES), m_returnMainMenu(false),
                              m_pause(Textures::texturesObject().getSprite(PAUSE_T)){
    srand(time(NULL));
    buildHouses();

    // Initialize pause menu.
    m_pause.add("Continue", std::make_unique<Continue>(0));
    m_pause.add("How To Play", std::make_unique<HowToPlay>(1));
    m_pause.add("Settings", std::make_unique<Settings>(2));
    m_pause.add("Exit", std::make_unique<Exit>(3, m_returnMainMenu));
}
//=============================================================================
void GamePlay::buildHouses() {

    // Creates the houses of the game according to iterators provided by the HousesFile class.

    while(!m_houseFile.eof()){
        auto houseDec = m_houseFile.getHouse();
        m_house.emplace_back(std::make_unique<Building>(houseDec.first, houseDec.second, m_playerStats,
                                                        BuildingBackGround_t(m_currHouse)));
        ++m_currHouse;
    }
    m_currHouse = 0;
}
//=============================================================================
bool GamePlay::execute(sf::RenderWindow & window) {

    Sounds::soundObject().playMusic(STAGE_MUSIC);

    m_clock.restart();
    while(window.isOpen()) {
        window.clear();

        auto houseDetails = m_house[m_currHouse]->runBuilding(window);
        if (houseDetails.m_GameOver) {
            GameOver(window);
            break;
        }

        // Checks
        if (houseDetails.m_killAllEnemy && houseDetails.m_allKeyCollected && houseDetails.m_allRoomComplete) {
            if (++m_currHouse == m_house.size()) {
                GameComplete(window);
                break;
            }
            LevelUp(window);
            m_clock.restart();
        }

        draw(window);

        for(auto event = sf::Event{}; window.pollEvent(event);){
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    exit(EXIT_SUCCESS);

                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            pauseMenu(window);
                            if(m_returnMainMenu){
                                restartGame(window);
                                m_returnMainMenu = false;
                                return true;
                            }
                            m_clock.restart();
                            break;
                        case sf::Keyboard::K:
                            GameOver(window);
                            return true;
                    }
            }
        }
        window.display();
    }

    return true;
}
//=============================================================================
void GamePlay::draw(sf::RenderWindow & window) {
    m_house[m_currHouse]->draw(window, m_clock.restart());
}
//=============================================================================
void GamePlay::GameComplete(sf::RenderWindow & window) {
    --m_currHouse;

    window.setView(window.getDefaultView());

    Sounds::soundObject().stopMusic(STAGE_MUSIC);
    Sounds::soundObject().playMusic(WIN_MUSIC);

    // Display game complete screen.
    displayScreen(window, WIN_T);

    Sounds::soundObject().stopMusic(WIN_MUSIC);

    restartGame(window);
}
//=============================================================================
void GamePlay::GameOver(sf::RenderWindow & window) {

    window.setView(window.getDefaultView());

    Sounds::soundObject().stopMusic(STAGE_MUSIC);
    Sounds::soundObject().playMusic(GAME_OVER_MUSIC);

    // Display game over screen.
    displayScreen(window, GAME_OVER_T);

    Sounds::soundObject().stopMusic(GAME_OVER_MUSIC);

    restartGame(window);
}
//=============================================================================
void GamePlay::LevelUp(sf::RenderWindow & window) {

    window.setView(window.getDefaultView());

    Sounds::soundObject().playSound(LEVEL_UP_SOUND);

    // Display level up screen.
    displayScreen(window, LEVEL_UP_T);

    Sounds::soundObject().stopSound(LEVEL_UP_SOUND);
}
//=============================================================================
void GamePlay::restartGame(sf::RenderWindow & window) {

    // Initialize the houses to start the game again.

    // The function initializes only the houses that was played.

    for(auto house = 0; house <= m_currHouse; ++house){
        m_houseFile.lseek(house);
        auto houseDec = m_houseFile.getHouse();
        m_house[house] = std::make_unique<Building>(houseDec.first, houseDec.second,
                                                    m_playerStats, BuildingBackGround_t(house));
    }

    m_currHouse = 0;
    m_playerStats = PlayerStats();
}
//=============================================================================
void GamePlay::displayScreen(sf::RenderWindow & window, Textures_t screen) {

    // Displays requested screen.

    auto sprite = sf::Sprite();
    sprite = Textures::texturesObject().getSprite(screen);
    sprite.setScale(WINDOW_SIZE.first / sprite.getGlobalBounds().width,
                    WINDOW_SIZE.second / sprite.getGlobalBounds().height);
    window.clear();
    window.draw(sprite);
    window.display();
    sf::sleep(sf::seconds(TRANSITION_SCREEN_TIME));
}
//=============================================================================
void GamePlay::pauseMenu(sf::RenderWindow & window) {

    window.setView(window.getDefaultView());

    m_pause.activate(window);

    Sounds::soundObject().playMusic(STAGE_MUSIC);
}
//=============================================================================