#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

#include "Macros.h"
#include "Textures.h"
#include "Sounds.h"
#include "Font.h"

class Screen {
public:
    //--------------------Virtual Function Section--------------------
    virtual enum ScreenType_t display(sf::RenderWindow &) = 0;
    virtual void draw(sf::RenderWindow &) = 0;


private:
};