#include "Audio.h"


Audio::Audio(const int pos) : Command(pos, "Music: ON") {}

bool Audio::execute(sf::RenderWindow& window)
{
	switch (Sounds::soundObject().musicStatus()) {
	case true:
		Sounds::soundObject().setMusicMute(false);
		setButtonTitle("Music: ON");
		break;
	case false:
		Sounds::soundObject().setMusicMute(true);
		setButtonTitle("Music: OFF");
		break;
	}
	return true;
}
