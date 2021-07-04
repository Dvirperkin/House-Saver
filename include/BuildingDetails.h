#pragma once

// This struct holds information about building.
struct BuildingDetails{

    bool m_allKeyCollected = false;

    bool m_killAllEnemy = false;

    bool m_allRoomComplete = false;

    // Indicates if player is died.
    bool m_GameOver = false;

    // Indicated if the player want to exit from the room.
    bool exit = false;
};