#include <SFML/Graphics.hpp>

#include "Menu.h"
#include "GamePlay.h"
#include "HowToPlay.h"
#include "Settings.h"
#include "QuitGame.h"

int main() try {

    auto window = sf::RenderWindow(sf::VideoMode(WINDOW_SIZE.first, WINDOW_SIZE.second), "The House Saver",
                                   sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    Menu HouseSaver(Textures::texturesObject().getSprite(MENU_BACK_GROUND));
    HouseSaver.add("New Game", std::make_unique<GamePlay>(0));
    HouseSaver.add("How To Play", std::make_unique<HowToPlay>(1));
    HouseSaver.add("Settings", std::make_unique<Settings>(2));
    HouseSaver.add("Quit", std::make_unique<QuitGame>(3));

    HouseSaver.activate(window);


    return EXIT_SUCCESS;
}
//=============================================================================
catch (std::exception & e)
{
    std::ofstream logfile;
    logfile.open("log.txt");
    logfile << e.what() << std::endl;
    logfile.close();

    return EXIT_FAILURE;
}
//=============================================================================