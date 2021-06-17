#include "GamePlay.h"

GamePlay::GamePlay() : m_lastHouse(0), m_houseFile(HOUSES){

    buildHouses();
}
//=============================================================================
void GamePlay::buildHouses() {
    while(!m_houseFile.eof()){
        auto houseDec = m_houseFile.getHouse();
        m_house.emplace_back(std::make_unique<House>(houseDec.first, houseDec.second));
    }
}
//=============================================================================
enum ScreenType_t GamePlay::display(sf::RenderWindow & window) {

    m_house[m_lastHouse]->runBuilding(window);
    draw(window);
    return GAME_PLAY;
}
//=============================================================================
void GamePlay::draw(sf::RenderWindow & window) {
    m_house[m_lastHouse]->draw(window, m_clock.restart());
}
//=============================================================================