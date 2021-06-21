#pragma once

#include "PlayerStats.h"
#include "Mission.h"

struct BuildingDetails{
    PlayerStats m_stats;
    bool exit = false;
    bool m_missionComplete = false;
};