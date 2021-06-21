#include "Mission.h"

Mission::Mission(const int time): m_time(time){}

sf::Text Mission::CountDown()
{
    auto text = sf::Text();
    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
    text.setCharacterSize(40);
    text.setFont(Font::FontObject().getFont());
    auto timeString = std::string();
    timeString += "Time Left : ";
    timeString += std::to_string(m_time / HOUR);
    timeString += ":";

    if (m_time % MINUTE < 10)
        timeString += "0";

    timeString += std::to_string(m_time % MINUTE);
    text.setString(timeString);
    return text;
}

void Mission::UpdateTime(sf::Time deltaTime)
{
    static int second = 1;
    second -= deltaTime.asSeconds();
    if (second <= 0) {
        --m_time;
        second = 1;
    }
}

void Mission::draw(sf::RenderWindow & window)
{
    if(m_time != 0)
        window.draw(CountDown());
}
