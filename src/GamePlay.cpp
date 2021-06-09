#include "GamePlay.h"

GamePlay::GamePlay() : m_lastHouse(0), m_houseFile(HOUSES){

    buildHouses();
}
//=============================================================================
void GamePlay::buildHouses() {
    while(!m_houseFile.eof()){
        auto houseDeclarationRange = m_houseFile.getHouse();
        m_house.emplace_back(std::make_unique<House>(houseDeclarationRange.first,
                                                     houseDeclarationRange.second));
    }
}
//=============================================================================
enum ScreenType_t GamePlay::display(sf::RenderWindow & window) {

    m_house[m_lastHouse]->runHouse(window);
    draw(window);
    return GAME_PLAY;
}
//=============================================================================
void GamePlay::draw(sf::RenderWindow & window) {
    m_house[m_lastHouse]->draw(window, m_clock.restart());
}
//=============================================================================

