#pragma once

#include "Button.h"
#include "Textures.h"

// An abstract class that represent a command in a menu.

class Command {
public:
    //--------------------Constructor/Destructor Section--------------------
    Command(int pos, std::string text) : m_button(pos, text){}

    //--------------------Functions Section--------------------
    virtual bool execute(sf::RenderWindow &) = 0;
    bool isSelected(sf::Vector2f position) const { return m_button.isPressed(position); }
    void setButtonTitle(const std::string & title) { m_button.setString(title); }
    void draw(sf::RenderWindow & window) const { m_button.draw(window); }
    void setCharacterColor(const bool status) { m_button.setCharacterColor(status); }

private:
    Button m_button;
};

