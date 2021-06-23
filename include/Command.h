#pragma once

#include "Button.h"

class Command {
public:
    Command(int pos, std::string text) : m_button(pos, text){}
    virtual bool execut(sf::RenderWindow &) = 0;
    bool isSelected(sf::Vector2f position) const { return m_button.isPressed(position); }
    void draw(sf::RenderWindow & window) const {m_button.draw(window);}
private:
    Button m_button;
};