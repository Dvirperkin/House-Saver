#include "Settings.h"

Settings::Settings(const int pos): Command(pos, "Settings"), m_return(false),
                                    m_settings(Textures::texturesObject().getSprite(MENU_BACK_GROUND)){
    m_settings.add("SFX: ON", std::make_unique<SFX>(0));
    m_settings.add("Audio: ON", std::make_unique<Audio>(1));
    m_settings.add("Exit", std::make_unique<Exit>(2, m_return));
}
//=============================================================================
bool Settings::execute(sf::RenderWindow & window){
    m_settings.activate(window);
	return true;
}
//=============================================================================