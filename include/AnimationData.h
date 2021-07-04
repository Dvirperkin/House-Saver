#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

#include "Macros.h"


// That struct include an unordered map of IntRect vector in the value,
// that indicates all the position of the sprites in the sprites sheet.
// The key of the map is the type of the animation.

struct AnimationData
{
    using ListType = std::vector<sf::IntRect>;
    using DataType = std::unordered_map<AnimationStatus_t, ListType>;
    DataType m_data;
};
