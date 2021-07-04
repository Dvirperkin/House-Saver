#include "SFX.h"

SFX::SFX(const int pos) : Command(pos, "SFX: ON") {}
//=============================================================================
bool SFX::execute(sf::RenderWindow & window){

	switch (Sounds::soundObject().soundStatus()) {
	case true:
		Sounds::soundObject().setSoundMute(false);
		setButtonTitle("SFX: ON");
		break;

	case false:
		Sounds::soundObject().setSoundMute(true);
		setButtonTitle("SFX: OFF");
		break;
	}

	return true;
}
//=============================================================================