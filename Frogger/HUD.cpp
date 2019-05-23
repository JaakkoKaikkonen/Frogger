#include "HUD.hpp"
#include "DEFINITIONS.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include "utility.hpp"

namespace Game {

	HUD::HUD(gameDataRef data)
		: _data(data), _score("00000", _data->assets.getFont("Font"), 24), _highScoreText("HIGH SCORE", _data->assets.getFont("Font"), 24),
		_highScore("00000", _data->assets.getFont("Font"), 24), _timeText("TIME", _data->assets.getFont("Font"), 24), _timer(sf::Vector2f(8*TILE_SIZE, TILE_SIZE / 2))
	{
		_score.setOrigin(_score.getGlobalBounds().width, 0.0f);
		_score.setPosition(168.0f, 28.0f);
		_score.setFillColor(sf::Color::Red);


		//Read highscore
		std::ifstream highScoreFile;
		highScoreFile.open(HIGH_SCORE_FILEPATH);

		if (highScoreFile.is_open()) {
			int highScore;
			highScoreFile >> highScore;
			_highScore.setString(std::string("00000").erase(0, std::to_string(std::stoi((std::string)_highScore.getString()) + highScore).length()) + std::to_string(std::stoi((std::string)_score.getString()) + highScore));
		} else {
			std::cout << "Highscore file not found" << std::endl;
		}


		_highScoreText.setPosition(SCREEN_WIDTH / 2 - _highScoreText.getGlobalBounds().width / 2, 2.0f);

		_highScore.setOrigin(_highScore.getGlobalBounds().width, 0.0f);
		_highScore.setPosition(SCREEN_WIDTH / 2, 28.0f);
		_highScore.setFillColor(sf::Color::Red);


		_timeText.setPosition(12*TILE_SIZE, 15*TILE_SIZE + TILE_SIZE / 2 - 3);
		_timeText.setFillColor(sf::Color::Yellow);

		_timer.setFillColor(sf::Color(33, 222, 0));
		_timer.setOrigin(_timer.getGlobalBounds().width, 0.0f);
		_timer.setPosition(12*TILE_SIZE - 2, 15*TILE_SIZE + TILE_SIZE / 2);

	}

	HUD::~HUD()
	{
	}

	void HUD::drawScore() {
		_score.setOrigin(_score.getGlobalBounds().width, 0.0f);
		_data->window.draw(_score);
	}


	void HUD::drawHighScore() {

		_data->window.draw(_highScoreText);

		if (std::stoi((std::string)_score.getString()) > std::stoi((std::string)_highScore.getString())) {
			_highScore.setString(_score.getString());
		}

		_highScore.setOrigin(_highScore.getGlobalBounds().width / 2, 0.0f);
		_data->window.draw(_highScore);

	}

	void HUD::drawTime() {
		_data->window.draw(_timeText);
		_data->window.draw(_timer);
	}

	void HUD::setTime(const int& levelTimer) {
		_timer.setFillColor(sf::Color(33, 222, 0));
		_timer.setSize(sf::Vector2f(utility::map((float)levelTimer, 0.0f, TIME, 8.0f*TILE_SIZE, 0.0f), TILE_SIZE / 2));
		_timer.setOrigin(_timer.getGlobalBounds().width, 0.0f);
		if (levelTimer > 25) {
			_timer.setFillColor(sf::Color::Red);
		}
	}

	void HUD::addToScore(const int score) {
		_score.setString(std::string("00000").erase(0, std::to_string(std::stoi((std::string)_score.getString()) + score).length()) + std::to_string(std::stoi((std::string)_score.getString()) + score));
	}

	void HUD::resetScore() {
		_score.setString("00000");
	}

	void HUD::saveHighScore() {

		//Save highscore
		std::ofstream highScoreFile(HIGH_SCORE_FILEPATH);

		if (highScoreFile.is_open()) {
			highScoreFile << std::stoi((std::string)_highScore.getString());
		} else {
			std::cout << "Highscore file not found" << std::endl;
		}

	}

}