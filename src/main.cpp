#include <SFML/Graphics.hpp>

#include "Menu.h"
#include "GamePlay.h"

int main() {

    auto window = sf::RenderWindow(sf::VideoMode(WINDOW_SIZE.first, WINDOW_SIZE.second), "HouseSaver");
    window.setFramerateLimit(60);

    Menu HouseSaver;
    HouseSaver.add("GamePlay", std::make_unique<GamePlay>(0));

    HouseSaver.activate(window);


    return 0;
}
