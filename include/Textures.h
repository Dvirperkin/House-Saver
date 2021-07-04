#pragma once

#include <SFML/Graphics.hpp>

#include "Macros.h"
#include "AnimationData.h"

class Textures {
public:

    static Textures & texturesObject();

    //--------------------Get Function Section--------------------
    const sf::Sprite getSprite(enum Textures_t image) { return sf::Sprite(m_textures[image]); }
    const sf::Texture & getTexture(enum Textures_t image) { return m_textures[image]; }
    const AnimationData & animationData(ObjectsData_t objectsData) { return m_animationsData[objectsData]; }
    const sf::Sprite getHouseSprite(enum BuildingBackGround_t house) { return sf::Sprite(m_BuildingsSprites[house]); }

private:
    std::vector<sf::Texture> m_BuildingsSprites;
    std::vector<sf::Texture> m_textures;
    std::vector<AnimationData> m_animationsData;

    //--------------------Constructor/Destructor Section--------------------
    Textures();
    Textures(const Textures &) = default;
    Textures& operator=(const Textures &) = default;

    void openTexture(Textures_t, const std::string &);
    void openBuildingTexture(BuildingBackGround_t, const std::string &);
};






