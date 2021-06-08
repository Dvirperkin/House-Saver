#pragma once

#include "Screen.h"

class MainMenu : public Screen{
public:
    enum ScreenType_t display(sf::RenderWindow &) override {return MAIN_MENU;}
    void draw(sf::RenderWindow &) override {}
private:
};