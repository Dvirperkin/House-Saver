#include "GameController.h"
#include <iostream>

GameController::GameController() : m_currentScreen(PLAY){
    m_screens.emplace_back(std::make_unique<MainMenu>());
    m_screens.emplace_back(std::make_unique<GamePlay>());
}
//=============================================================================
void GameController::run() {
    auto window = sf::RenderWindow(sf::VideoMode(1000,1000), "HouseSaver");
    window.setFramerateLimit(60);

    auto view = window.getView();
    window.setView(view);


    while(window.isOpen()) {
        window.clear();
        switch(m_currentScreen){
            case MAIN_MENU:
                m_currentScreen = m_screens[MAIN_MENU]->display(window);
                break;

            case PLAY:
                m_currentScreen = m_screens[PLAY]->display(window);
                break;

            case EXIT:
                window.close();
                break;
        }
        window.display();

        for (auto event = sf::Event{}; window.pollEvent(event);) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }


    }
}