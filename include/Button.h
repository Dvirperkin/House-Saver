#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "Macros.h"
#include "Font.h"

class Button {
public:
    //--------------------Constructor/Destructor Section--------------------
    Button(int, std::string &);

    //--------------------Action Function Section--------------------
    void draw(sf::RenderWindow &) const;
    bool isPressed (const sf::Vector2f &) const;

    //--------------------Get Function Section--------------------
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBound() const;

	void setString(const std::string& str);

    //--------------------Set Function Section--------------------
    void setCharacterColor(const bool);

private:
    sf::RectangleShape m_frame;
    sf::Text m_buttonText;
};