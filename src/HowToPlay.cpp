#include "HowToPlay.h"

HowToPlay::HowToPlay(const int pos):Command(pos, "How To Play"){}
//=============================================================================
bool HowToPlay::execute(sf::RenderWindow & window){

	auto howToPlay = Textures::texturesObject().getSprite(HOW_TO_PLAY_T);

	howToPlay.setScale(WINDOW_SIZE.first / howToPlay.getGlobalBounds().width,
		WINDOW_SIZE.second / howToPlay.getGlobalBounds().height);


	while (window.isOpen()) {
		window.clear();
		window.draw(howToPlay);
		window.display();
		for (auto event = sf::Event{}; window.waitEvent(event);) {
			switch (event.type){

			case sf::Event::Closed:
				window.close();
				exit(EXIT_SUCCESS);
			case sf::Event::KeyReleased:
				return true;
			default:
				break;
			}
		}
	}
	return true;
}
//=============================================================================