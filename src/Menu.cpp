#include "Menu.h"

Menu::Menu(const sf::Sprite & backGround) : m_backGround(backGround),
                                            m_lastCommandBold(DO_NOTHING){

    m_backGround.setScale(WINDOW_SIZE.first / m_backGround.getGlobalBounds().width,
                          WINDOW_SIZE.second / m_backGround.getGlobalBounds().height);
}
//=============================================================================
void Menu::add(const std::string & name, std::unique_ptr<Command> command){
    m_options.emplace_back(option(name, std::move(command)));
}
//=============================================================================
void Menu::activate(sf::RenderWindow & window) {

    int command;

    do{
        draw(window);
        command = getCommand(window);
    } while (performAction(window, command));
}
//=============================================================================
int Menu::getCommand(sf::RenderWindow & window) {

    while(true) {

        draw(window);

        for (auto event = sf::Event{}; window.pollEvent(event);) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    exit(EXIT_SUCCESS);
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Button::Left) {
                        return click(window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y}));
                    }
                    break;
                case sf::Event::KeyReleased:
                    if (event.key.code == sf::Keyboard::Escape) {
                        if (m_options[0].first == "Continue")
                            return 0;
                        return (m_options.size() - 1);
                    }
                    break;
                case sf::Event::MouseMoved:
                    handleMouseMove(window, window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y}));
                    break;
            }
        }
    }

    return false;
}
//=============================================================================
int Menu::click(sf::Vector2f position) {

    for(int option = 0; option < m_options.size(); ++option){
        if(m_options[option].second->isSelected(position)) {
            Sounds::soundObject().playSound(BUTTON_CLICK_SOUND);
            return option;
        }
    }
    return NO_COMMAND;
}
//=============================================================================
bool Menu::performAction(sf::RenderWindow & window, int option) {
    if(option == NO_COMMAND)
        return true;
    return m_options[option].second->execute(window);
}
//=============================================================================
void Menu::draw(sf::RenderWindow & window) {

    window.clear();

    window.draw(m_backGround);

    for(auto & option : m_options){
        option.second->draw(window);
    }

    window.display();
}
//=============================================================================
void Menu::handleMouseMove(sf::RenderWindow & window, const sf::Vector2f & location) {

    for(auto i = 0; i < m_options.size(); ++i){
        if(m_options[i].second->isSelected(location)){
            if(i != m_lastCommandBold){
                m_options[i].second->setCharacterColor(true);

                if(m_lastCommandBold != DO_NOTHING){
                    m_options[m_lastCommandBold].second->setCharacterColor(false);
                    m_options[m_lastCommandBold].second->draw(window);
                }
                m_lastCommandBold = i;
            }
            return;
        }
    }

    if(m_lastCommandBold != DO_NOTHING)
        m_options[m_lastCommandBold].second->setCharacterColor(false);
    m_lastCommandBold = DO_NOTHING;
}
//=============================================================================