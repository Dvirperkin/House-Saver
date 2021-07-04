#include "Button.h"

Button::Button(int position, std::string & text)
    : m_frame(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT)), m_buttonText(text, Font::FontObject().getFont()){

    m_frame.setPosition(BUTTON_WIDTH, ((WINDOW_SIZE.second / 3) + (BUTTON_HEIGHT * position) + (50 * position)));
    m_frame.setOutlineColor(sf::Color::Transparent);
    m_frame.setFillColor(sf::Color::Transparent);

    m_buttonText.setCharacterSize(BUTTON_CHAR_SIZE);
    m_buttonText.setOrigin(m_buttonText.getGlobalBounds().width / 2, m_buttonText.getGlobalBounds().height / 2);
    m_buttonText.setPosition(getPosition().x + getGlobalBound().width / 2,
                                    getPosition().y + getGlobalBound().height / 2 - CHARACTER_SIZE / 3);
    m_buttonText.setFillColor(sf::Color::Black);
    m_buttonText.setOutlineColor(sf::Color::White);
    m_buttonText.setOutlineThickness(THICKNESS);
}
//=============================================================================
bool Button::isPressed (const sf::Vector2f & position) const{

    if(m_frame.getGlobalBounds().contains(position))
        return true;
    return false;
}
//=============================================================================
void Button::draw(sf::RenderWindow & window) const{
    window.draw(m_frame);
    window.draw(m_buttonText);
}
//=============================================================================
void Button::setCharacterColor(const bool status) {
    if(status)
        m_buttonText.setOutlineColor(sf::Color::Red);
    else
        m_buttonText.setOutlineColor(sf::Color::White);
}
//=============================================================================
sf::Vector2f Button::getPosition() const{
    return m_frame.getPosition();
}
//=============================================================================
sf::FloatRect Button::getGlobalBound() const {
    return m_frame.getGlobalBounds();
}
//=============================================================================
void Button::setString(const std::string & str){
    m_buttonText.setString(str);
}
//=============================================================================