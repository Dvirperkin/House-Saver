#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <string>

#include "Command.h"
#include "Macros.h"
#include "Textures.h"
#include "Sounds.h"

// A class that implements a menu according to command design pattern principles.

class Menu {
public:
    //----------Constructors\Destructors Section----------
    Menu(const sf::Sprite &);

    //----------Functions Section----------
    void add(const std::string &, std::unique_ptr<Command>);
    void activate(sf::RenderWindow &);

private:
    typedef std::pair<std::string, std::unique_ptr<Command>> option;
    std::vector<option> m_options;
    sf::Sprite m_backGround;

    int m_lastCommandBold;

    int getCommand(sf::RenderWindow &);
    int click(sf::Vector2f);
    void draw(sf::RenderWindow &);
    void handleMouseMove(sf::RenderWindow &, const sf::Vector2f &);

    bool performAction(sf::RenderWindow &, int);
};