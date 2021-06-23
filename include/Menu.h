#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <string>

#include "Command.h"
#include "Macros.h"
#include "Textures.h"

class Menu {
public:
    Menu();
    void add(const std::string &, std::unique_ptr<Command>);
    void activate(sf::RenderWindow &);

private:
    typedef std::pair<std::string, std::unique_ptr<Command>> option;
    std::vector<option> m_options;
    sf::Sprite m_backGround;

    int getCommand(sf::RenderWindow &);
    int click(sf::Vector2f);
    void draw(sf::RenderWindow &);

    bool performAction(sf::RenderWindow &, int);
};