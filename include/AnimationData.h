#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

#include "Macros.h"

struct AnimationData
{
    using ListType = std::vector<sf::IntRect>;
    using DataType = std::unordered_map<AnimationStatus_t, ListType>;
    DataType m_data;
};
