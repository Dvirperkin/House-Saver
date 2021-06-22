#pragma once

#include <SFML/Graphics.hpp>
#include <utility>

#include "Macros.h"
#include "Textures.h"
#include "Font.h"

class PlayerStats {
public:
	PlayerStats();
	void keyCollected();

	int getLives() const { return m_lives.first; }
	int getHP() const { return m_lives.second; }
	int getKeys()const { return m_keyCollected; }
	void addScore(const int);
	void decreaseHP(const int);
	void increaseHP();

	void increaseLife();

	void display(sf::RenderWindow&);
	void drawDetail(sf::RenderWindow&, const std::string &, PlayerStats_t);

private:
	int m_score = 0;
	int m_keyCollected = 0;
	std::pair<int, int> m_lives = {START_LIVES, START_HP};
	std::vector<sf::Text> m_details;
};
