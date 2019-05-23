#pragma once

#include <SFML\Graphics.hpp>
#include "Game.hpp"

namespace Game {

	class HUD
	{
	public:
		HUD(gameDataRef data);
		~HUD();

		void drawScore();

		void drawHighScore();

		void drawTime();

		void setTime(const int& levelTimer);

		void addToScore(const int score);

		void resetScore();

		void saveHighScore();

	private:
		gameDataRef _data;

		sf::Text _score;

		sf::Text _highScoreText;

		sf::Text _highScore;

		sf::Text _timeText;

		sf::RectangleShape _timer;
	};


}

