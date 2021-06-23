#include "GamePlay.h"

GamePlay::GamePlay(int pos) : Command(pos, "GamePlay"),
                              m_currHouse(0), m_houseFile(HOUSES){
    srand(time(NULL));
    buildHouses();
}
//=============================================================================
void GamePlay::buildHouses() {
    while(!m_houseFile.eof()){
        auto houseDec = m_houseFile.getHouse();
        m_house.emplace_back(std::make_unique<Building>(houseDec.first, houseDec.second,m_playerStats));
    }
}
//=============================================================================
bool GamePlay::execut(sf::RenderWindow & window) {

    m_clock.restart();

    while(window.isOpen()) {
        window.clear();

        auto houseDetails = m_house[m_currHouse]->runBuilding(window);
        if (houseDetails.m_GameOver) {
            GameOver(window);
            break;
        }
        if (houseDetails.m_missionComplete) {
            if (++m_currHouse == m_house.size()) {
                GameComplete(window);
                break;
            }
        }
        draw(window);

        for(auto event = sf::Event{}; window.pollEvent(event);){
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    exit(EXIT_SUCCESS);
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Escape){}
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
void GamePlay::GameComplete(sf::RenderWindow &) {
    restartGame();
}
//=============================================================================
void GamePlay::GameOver(sf::RenderWindow &) {
    restartGame();
}
//=============================================================================
void GamePlay::restartGame() {

    for(auto house = m_currHouse; house >= 0; --house){
        m_houseFile.lseek(house);
        auto houseDec = m_houseFile.getHouse();
        m_house[house] = std::make_unique<Building>(houseDec.first, houseDec.second, m_playerStats);
    }

    m_currHouse = 0;
    m_playerStats = PlayerStats();

    buildHouses();
}
//=============================================================================
void GamePlay::pauseMenu(sf::RenderWindow &) {

}
//=============================================================================