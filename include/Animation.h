#pragma once

#include <SFML/Graphics.hpp>

#include "AnimationData.h"
#include "Textures.h"

// A class that implement animation for creating game objects animation.

class Animation
{
public:
    //Constructor 
    Animation(const AnimationData& data, AnimationStatus_t dir, sf::Sprite& sprite, const sf::Vector2f&);

    void setStatus(AnimationStatus_t dir); //Set animation status
    
    void update(sf::Time delta); // Update animation figure

private:
    void update();
    sf::Vector2f m_dimension;
    const AnimationData& m_data;
    sf::Time m_elapsed = {};
    AnimationStatus_t m_status = AnimationStatus_t::Idle;
    int m_index = 0;
    sf::Sprite& m_sprite;
};
