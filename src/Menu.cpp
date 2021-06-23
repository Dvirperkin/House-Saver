#include "Menu.h"

Menu::Menu() : m_backGround(Textures::texturesObject().getSprite(MenuBackGround)){

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

    for(auto event = sf::Event{}; window.waitEvent(event);){
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                exit(EXIT_SUCCESS);
            case sf::Event::MouseButtonPressed:
                if(event.mouseButton.button == sf::Mouse::Button::Left){
                    return click(window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y}));
                }
        }
    }

    return 0;
}
//=============================================================================
int Menu::click(sf::Vector2f position) {

    for(int option = 0; option < m_options.size(); ++option){
        if(m_options[option].second->isSelected(position))
            return option;
    }
    return NO_COMMAND;
}
//=============================================================================
bool Menu::performAction(sf::RenderWindow & window, int option) {
    if(option == NO_COMMAND)
        return true;
    return m_options[option].second->execut(window);
}
//=============================================================================
void Menu::draw(sf::RenderWindow & window) {

    window.setView(window.getDefaultView());
    window.clear();

    window.draw(m_backGround);

    for(auto & option : m_options){
        option.second->draw(window);
    }

    window.display();
}
//=============================================================================