#pragma once

#include <SFML/Graphics.hpp>

#include "AnimationData.h"
#include "Textures.h"

// A class that implement animation for creating game objects animation.

class Animation{
public:
    //--------------------Constructor/Destructor Section--------------------
    Animation(const AnimationData & data, AnimationStatus_t, sf::Sprite &, const sf::Vector2f &);

    //--------------------Functions Section--------------------

    //Set animation status
    void setStatus(AnimationStatus_t);

    // Update animation figure
    void update(sf::Time);

private:
    int m_index = 0;
    sf::Sprite& m_sprite;
    sf::Time m_elapsed = {};
    sf::Vector2f m_dimension;
    const AnimationData& m_data;
    AnimationStatus_t m_status = AnimationStatus_t::Idle;

    void update();
};
