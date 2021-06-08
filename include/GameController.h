#pragma once

#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "MainMenu.h"
#include "GamePlay.h"

class GameController {
public:
    GameController();
    void run();

private:
    enum ScreenType_t m_currentScreen;
    std::vector<std::unique_ptr<Screen>> m_screens;
};