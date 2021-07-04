#include "PlayerStats.h"

PlayerStats::PlayerStats(): m_score(0), m_lives(START_LIVES, START_HP), m_keyCollected(0){
	m_details.resize(NUM_OF_DETAILS);
}
//=============================================================================
void PlayerStats::addScore(const int score) {
	m_score += score;
}
//=============================================================================
void PlayerStats::decreaseHP(const int hitPoint) {
    m_lives.second -= hitPoint;

    if(m_lives.second <= 0) {
        --m_lives.first;
        if(m_lives.first < 0)
            m_lives.second = 0;
        if(m_lives.first > 0)
            m_lives.second = START_HP;
    }
}
//=============================================================================
void PlayerStats::increaseHP()
{
    m_lives.second += HP_INCREASE;

    if (m_lives.second > START_HP)
        m_lives.second = START_HP;
}
//=============================================================================
void PlayerStats::increaseLife()
{
    m_lives.first += 1;
    if (m_lives.first > MAX_LIVES)
        m_lives.first = MAX_LIVES;
}
//=============================================================================
void PlayerStats::keyCollected(){
	++m_keyCollected;
	addScore(SCORE_INCREASE);
}
//=============================================================================
void PlayerStats::display(sf::RenderWindow& window){

    // Draw the stats of the player on the screen.

    auto statBackGround = sf::RectangleShape({window.getView().getSize().x, CHARACTER_SIZE});
    statBackGround.setPosition(window.getView().getCenter().x - (window.getView().getSize().x / 2),
                               window.getView().getCenter().y - (window.getView().getSize().y / 2));
    statBackGround.setTexture(Textures::texturesObject().getSprite(STAT_BACKGROUND_T).getTexture());
    window.draw(statBackGround);

	drawDetail(window, "Live: " + std::to_string(m_lives.first), LIVE);
	drawDetail(window, "HP: " + std::to_string(m_lives.second), HP);
	drawDetail(window, "Keys: " + std::to_string(m_keyCollected) ,KEYS);
	drawDetail(window, "Score: " + std::to_string(m_score), SCORE);
}
//=============================================================================
void PlayerStats::drawDetail(sf::RenderWindow& window,const std::string& detail,PlayerStats_t index) {

    m_details[index].setFont(Font::FontObject().getFont());
    m_details[index].setString(detail);
    m_details[index].setCharacterSize(CHARACTER_SIZE);
    m_details[index].setFillColor(GRAY);
    m_details[index].setOrigin(m_details[index].getGlobalBounds().width / 2,
                               m_details[index].getGlobalBounds().height / 2);

    auto view = window.getView();
    auto viewPosX = view.getCenter().x - (view.getSize().x / 2);
    auto viewPosY = view.getCenter().y - (view.getSize().y / 2);

    m_details[index].setPosition(viewPosX + (view.getSize().x / NUM_OF_DETAILS) * (index + 0.5),
                                 viewPosY + 7);

    window.draw(m_details[index]);
}
//=============================================================================