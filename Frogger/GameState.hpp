#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "Frog.hpp"
#include "Car.hpp"
#include "HUD.hpp"
#include "Log.hpp"
#include "Turtle.hpp"
#include <vector>
#include <array>
#include <string>


namespace Game {

	class GameState : public State
	{
	public:
		GameState(gameDataRef data);

		void init();

		void handleInput();
		void update(float dt);
		void draw(float interpolation);

	private:
		void killFrog();

		void changeMusic(std::string filepath);

		void pauseMusic();

	private:
		gameDataRef _data;

		sf::RectangleShape _topBackground;

		HUD _hud;

		Frog _frog;

		bool _frogIsColliding = false;

		std::array<sf::Sprite, 3> _pads;

		std::array<Car*, 13> _cars;

		std::array<Log*, 9> _logs;

		std::array<Turtle*, 17> _turtles;

		std::array<sf::IntRect*, 5> _goals;

		std::array<sf::Sprite, 5> _goalFrogs;

		std::array<bool, 5> _goalsReached;
		int _goalsReachedCounter = 0;

		std::vector<sf::Sprite> _hp;

		std::array<std::string, 5> _froggerHomedMusics;

		sf::Clock _winTimer;

		sf::Clock _deathTimer;

		sf::Clock _goalFrogTimer;

		sf::Clock _levelTimer;

		sf::Clock _musicTimer;

		sf::Clock _musicPauseTimer;

		sf::Clock _gameOverTimer;

		int _goalFrogIndex = 0;

		bool _resetGame = false;

		bool _gameOver = false;

		bool _win = false;

		bool _timeWarning = true;

		float _musicDuration;
		
		bool _themeMusic = false;

		//sf::Vertex _line[2];

	};

}

