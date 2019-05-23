#include "Game.hpp"
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Game {

	Game::Game(int width, int height, std::string title) {

		sf::Image icon;
		icon.loadFromFile(TOP_ICON_FILEPATH);

		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		//_data->window.setVerticalSyncEnabled(true);
		//_data->window.setFramerateLimit(60);

		_data->window.setPosition(sf::Vector2i(550, 150));

		_data->window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


		//Load Resources ----------------------------------------------------------------------

		//Textures
		_data->assets.loadTexture("Frog", FROG_FILEPATH);
		_data->assets.loadTexture("Cars", CARS_FILEPATH);
		_data->assets.loadTexture("Pad", PAD_FILEPATH);
		_data->assets.loadTexture("Goal", GOAL_FILEPATH);
		_data->assets.loadTexture("Death", DEATH_FILEPATH);
		_data->assets.loadTexture("Logs", LOG_FILEPATH);
		_data->assets.loadTexture("Turtle", TURTLE_FILEPATH);
		_data->assets.loadTexture("GoalFrog", GOAL_FROG_FILEPATH);
		_data->assets.loadTexture("HP", HP_FILEPATH);

		//Sounds
		_data->assets.loadSound("Jump", JUMP_SOUND_FILEPATH);
		_data->assets.loadSound("Squash", SQUASH_SOUND_FILEPATH);
		_data->assets.loadSound("Plunk", PLUNK_SOUND_FILEPATH);
		_data->assets.loadSound("Time", TIME_SOUND_FILEPATH);

		//Fonts
		_data->assets.loadFont("Font", FONT_FILEPATH);

		//-------------------------------------------------------------------------------------

		_data->machine.addState(stateRef(new GameState(_data)), true);

		this->run();
	}

	void Game::run() {
		float newTime, frameTime;

		float currentTime = this->_clock.getElapsedTime().asSeconds();

		float accumulator = dt;

		float interpolation = 0.0f;


		while (this->_data->window.isOpen()) {

			this->_data->machine.processStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();

			frameTime = newTime - currentTime;

			currentTime = newTime;

			if (frameTime > 0.15f) {
				frameTime = 0.15f;
			}

			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.getActiveState()->handleInput();
				this->_data->machine.getActiveState()->update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;

			this->_data->machine.getActiveState()->draw(interpolation);


			//std::cout << 1 / frameTime << std::endl;
		}


	}


}