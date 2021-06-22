#pragma once

#include "PlayerStats.h"
#include "Mission.h"

struct BuildingDetails{
    PlayerStats m_stats;
    bool exit = false;
    bool m_allKeyCollected = false;
    bool m_killAllEnemy = false;
    bool m_missionComplete = false;
};