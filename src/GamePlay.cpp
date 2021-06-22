#include "GamePlay.h"

GamePlay::GamePlay() : m_lastHouse(0), m_houseFile(HOUSES){
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
enum ScreenType_t GamePlay::display(sf::RenderWindow & window) {

    auto houseDetails = m_house[m_lastHouse]->runBuilding(window);
    if (houseDetails.m_missionComplete) {
        if (++m_lastHouse == m_house.size()) {
            return MAIN_MENU;
        }
        //win 1 house
    }
    draw(window);
    return GAME_PLAY;
}
//=============================================================================
void GamePlay::draw(sf::RenderWindow & window) {
    m_house[m_lastHouse]->draw(window, m_clock.restart());
}
//=============================================================================