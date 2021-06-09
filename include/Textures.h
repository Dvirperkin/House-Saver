#pragma once
#include <SFML/Graphics.hpp>

#include "Macros.h"
#include "AnimationData.h"

class Textures {
public:

    static Textures & texturesObject();

    //--------------------Get Function Section--------------------
    const sf::Texture & getTexture(enum Textures_t);
    const sf::Sprite getSprite(enum Textures_t);
    const AnimationData & animationData(ObjectsData_t objectsData) {return m_animationsData[objectsData];}

private:
    std::vector<sf::Texture> m_textures;
    std::vector<AnimationData> m_animationsData;

    //--------------------Constructor/Destructor Section--------------------
    Textures();
    Textures(const Textures &) = default;
    Textures& operator=(const Textures &) = default;
};






