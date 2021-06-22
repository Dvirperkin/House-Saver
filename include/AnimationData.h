#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

#include "Macros.h"

// That struct create an unordered map of  animation vectors
// with there type as key in the map
struct AnimationData
{
    using ListType = std::vector<sf::IntRect>;
    using DataType = std::unordered_map<AnimationStatus_t, ListType>;
    DataType m_data;
};
