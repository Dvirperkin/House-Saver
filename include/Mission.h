#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Font.h"

class Mission {
public:
	Mission(const int);
	virtual MissionStatus_t MissionStatus() = 0;
	sf::Text CountDown();
	void UpdateTime(sf::Time);
	void draw(sf::RenderWindow&);

private:
	MissionStatus_t m_missionStatus;
	int m_time;
	sf::Clock m_clock;
};
