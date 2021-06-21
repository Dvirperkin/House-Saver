#include "GameController.h"

GameController::GameController() : m_currentScreen(GAME_PLAY){
    m_screens.emplace_back(std::make_unique<MainMenu>());
    m_screens.emplace_back(std::make_unique<GamePlay>());
}
//=============================================================================
void GameController::run() {
    auto window = sf::RenderWindow(sf::VideoMode(1000,1000), "HouseSaver");
    auto backGround = Textures::texturesObject().getSprite(BACKGROUND_T);
    window.setFramerateLimit(60);

    while(window.isOpen()) {
        window.clear();
        window.draw(backGround);

        switch(m_currentScreen){
            case MAIN_MENU:
                m_currentScreen = m_screens[MAIN_MENU]->display(window);
                break;

            case GAME_PLAY:
                m_currentScreen = m_screens[GAME_PLAY]->display(window);
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