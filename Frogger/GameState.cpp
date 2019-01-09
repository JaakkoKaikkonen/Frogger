#include <string>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>
#include "Utility.hpp"
#include "Collision.hpp"



namespace engine {

	GameState::GameState(gameDataRef data)
		: _data(data), _topBackground(sf::Vector2f(SCREEN_WIDTH, 9 * TILE_SIZE)), _hud(data), _frog(data, _hud)
	{
		_topBackground.setFillColor(sf::Color(0, 0, 71));

		_hp.reserve(MAX_LIFES);

		_pads[0].setTexture(_data->assets.getTexture("Pad"));
		_pads[0].setScale(3.0f, 3.0f);
		_pads[0].setPosition(0.0f, 14 * TILE_SIZE);
		_pads[1].setScale(3.0f, 3.0f);
		_pads[1].setTexture(_data->assets.getTexture("Pad"));
		_pads[1].setPosition(0.0f, 8 * TILE_SIZE);
		_pads[2].setScale(3.0f, 3.0f);
		_pads[2].setTexture(_data->assets.getTexture("Goal"));
		_pads[2].setPosition(0.0f, 1.5*TILE_SIZE);

		_cars[0] = new Car(_data, CAR_01, 100, 13 * TILE_SIZE + TILE_SIZE / 2);
		_cars[1] = new Car(_data, CAR_01, 350, 13 * TILE_SIZE + TILE_SIZE / 2);
		_cars[2] = new Car(_data, CAR_01, 600, 13 * TILE_SIZE + TILE_SIZE / 2);
		_cars[3] = new Car(_data, CAR_02, 100, 12 * TILE_SIZE + TILE_SIZE / 2);
		_cars[4] = new Car(_data, CAR_02, 350, 12 * TILE_SIZE + TILE_SIZE / 2);
		_cars[5] = new Car(_data, CAR_02, 600, 12 * TILE_SIZE + TILE_SIZE / 2);
		_cars[6] = new Car(_data, CAR_03, 200, 11 * TILE_SIZE + TILE_SIZE / 2);
		_cars[7] = new Car(_data, CAR_03, 450, 11 * TILE_SIZE + TILE_SIZE / 2);
		_cars[8] = new Car(_data, CAR_03, 700, 11 * TILE_SIZE + TILE_SIZE / 2);
		_cars[9] = new Car(_data, CAR_04, 300, 10 * TILE_SIZE + TILE_SIZE / 2);
		_cars[10] = new Car(_data, CAR_05, 100, 9 * TILE_SIZE + TILE_SIZE / 2);
		_cars[11] = new Car(_data, CAR_05, 350, 9 * TILE_SIZE + TILE_SIZE / 2);
		_cars[12] = new Car(_data, CAR_05, 600, 9 * TILE_SIZE + TILE_SIZE / 2);

		_logs[0] = new Log(_data, LOG_01, 150, 6 * TILE_SIZE + TILE_SIZE / 2);
		_logs[1] = new Log(_data, LOG_01, 400, 6 * TILE_SIZE + TILE_SIZE / 2);
		_logs[2] = new Log(_data, LOG_01, 650, 6 * TILE_SIZE + TILE_SIZE / 2);
		_logs[3] = new Log(_data, LOG_03, 0, 5 * TILE_SIZE + TILE_SIZE / 2);
		_logs[4] = new Log(_data, LOG_03, 300, 5 * TILE_SIZE + TILE_SIZE / 2);
		_logs[5] = new Log(_data, LOG_03, 650, 5 * TILE_SIZE + TILE_SIZE / 2);
		_logs[6] = new Log(_data, LOG_02, 50, 3 * TILE_SIZE + TILE_SIZE / 2);
		_logs[7] = new Log(_data, LOG_02, 350, 3 * TILE_SIZE + TILE_SIZE / 2);
		_logs[8] = new Log(_data, LOG_02, 650, 3 * TILE_SIZE + TILE_SIZE / 2);

		_turtles[0] = new Turtle(_data, 50, 7 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[1] = new Turtle(_data, 100, 7 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[2] = new Turtle(_data, 150, 7 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[3] = new Turtle(_data, 300, 7 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[4] = new Turtle(_data, 350, 7 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[5] = new Turtle(_data, 400, 7 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[6] = new Turtle(_data, 550, 7 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[7] = new Turtle(_data, 600, 7 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[8] = new Turtle(_data, 650, 7 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[9] = new Turtle(_data, 50, 4 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[10] = new Turtle(_data, 100, 4 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[11] = new Turtle(_data, 225, 4 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[12] = new Turtle(_data, 275, 4 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[13] = new Turtle(_data, 400, 4 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[14] = new Turtle(_data, 450, 4 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[15] = new Turtle(_data, 575, 4 * TILE_SIZE + TILE_SIZE / 2);
		_turtles[16] = new Turtle(_data, 625, 4 * TILE_SIZE + TILE_SIZE / 2);


		for (int i = 0; i < _goals.size(); i++) {
			_goals[i] = new sf::IntRect(3 * i * TILE_SIZE + TILE_SIZE / 2, 2 * TILE_SIZE, TILE_SIZE, TILE_SIZE);

			_goalFrogs[i].setTexture(_data->assets.getTexture("GoalFrog"));
			_goalFrogs[i].setTextureRect(GOAL_FROG_01);
			_goalFrogs[i].setOrigin(_goalFrogs[i].getGlobalBounds().width / 2, _goalFrogs[i].getGlobalBounds().height / 2);
			_goalFrogs[i].setScale(3.0f, 3.0f);
			_goalFrogs[i].setPosition((float)3 * i * TILE_SIZE + TILE_SIZE, (float)2 * TILE_SIZE + TILE_SIZE / 2);
		}

		
		_froggerHomedMusics[0] = FROG_HOMED_01_FILEPATH;
		_froggerHomedMusics[1] = FROG_HOMED_02_FILEPATH;
		_froggerHomedMusics[2] = FROG_HOMED_03_FILEPATH;
		_froggerHomedMusics[3] = FROG_HOMED_04_FILEPATH;
		_froggerHomedMusics[4] = FROG_HOMED_05_FILEPATH;
		
	}

	void GameState::init() {
		std::cout << "Game state" << std::endl;

		_hud.resetScore();

		_resetGame = false;
		_levelTimer.restart();
		_timeWarning = true;
		_gameOver = false;

		memset(&_goalsReached, 0, sizeof(bool) * _goalsReached.size());
		_goalsReachedCounter = 0;


		for (int i = 0; i < MAX_LIFES; i++) {
			_hp.emplace_back(sf::Sprite(_data->assets.getTexture("HP")));
			_hp[i].setScale(3.0f, 3.0f);
			_hp[i].setPosition((i * _hp[i].getGlobalBounds().width) + 3*i + 2, 15*TILE_SIZE + 2);
		}

		this->changeMusic(START_MUSIC_FILEPATH);
	
	}

	void GameState::handleInput() {
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_hud.saveHighScore();
				_data->window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			_frog.restart();
		}


		if (!_frog.death() && !_win) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				_frog.move(Dir::Up);
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				if (_frog.getSprite().getPosition().y < 14*TILE_SIZE) {
					_frog.move(Dir::Down);
				}
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				_frog.move(Dir::Right);
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				_frog.move(Dir::Left);
			}

		}

	}

	void GameState::update(float dt) {

		_frogIsColliding = false;


		//Move stuff
		for (int i = 0; i < _cars.size(); i++) {
			_cars[i]->move();
		}
		for (int i = 0; i < _logs.size(); i++) {
			_logs[i]->move();
		}
		for (int i = 0; i < _turtles.size(); i++) {
			_turtles[i]->move();
		}
		

		if (!_frog.death()) {

			if (_goalsReachedCounter == 5) {
				_win = true;
				if (_goalFrogTimer.getElapsedTime().asSeconds() > 1.0f && _goalFrogIndex < _goals.size()) {
					_goalFrogs[_goalFrogIndex].setTextureRect(GOAL_FROG_02);
					_goalFrogIndex++;
					_goalFrogTimer.restart();
				}
				if (_winTimer.getElapsedTime().asSeconds() > 6.0f) {
					_hud.addToScore(1000);
					_goalsReachedCounter = 0;
					memset(&_goalsReached, 0, sizeof(bool) * _goalsReached.size());
					_levelTimer.restart();
					_frog.restart();
					_win = false;
					_goalFrogIndex = 0;
					for (int i = 0; i < _goalFrogs.size(); i++) {
						_goalFrogs[i].setTextureRect(GOAL_FROG_01);
					}
				}
				return;
			}

			for (int i = 0; i < _goals.size(); i++) {
				if (_goals[i]->contains((sf::Vector2i)_frog.getSprite().getPosition())) {
					if (!_goalsReached[i]) {
						this->changeMusic(_froggerHomedMusics[_goalsReachedCounter]);
						_hud.addToScore(50);
						_goalsReached[i] = true;
						_goalsReachedCounter++;
						_winTimer.restart();
						_levelTimer.restart();
						_timeWarning = true;
						_goalFrogTimer.restart();
						_frog.restart();
					} else {
						this->killFrog();
					}
				}
			}

			for (int i = 0; i < _cars.size(); i++) {
				if (Collision::checkSpriteCollision(_frog.getSprite(), 0.6f, _cars[i]->getSprite(), 1.0f)) {
					this->pauseMusic();
					_data->assets.getSound("Squash").play();
					this->killFrog();
				}
			}
			for (int i = 0; i < _turtles.size(); i++) {
				if (Collision::checkSpriteCollision(_frog.getSprite(), 0.5f, _turtles[i]->getSprite(), 1.0f)) {
					_frog.getSprite().move(_turtles[i]->getSpeed(), 0.0f);
					_frogIsColliding = true;
				}
			}
			for (int i = 0; i < _logs.size(); i++) {
				if (Collision::checkSpriteCollision(_frog.getSprite(), 0.5f, _logs[i]->getSprite(), 1.0f)) {
					_frog.getSprite().move(_logs[i]->getSpeed(), 0.0f);
					_frogIsColliding = true;
				}
			}

			if ((_frog.getSprite().getPosition().y < 8*TILE_SIZE && !_frogIsColliding) || 
				(_frog.getSprite().getPosition().x > SCREEN_WIDTH + _frog.getSprite().getGlobalBounds().width / 2) ||
				_frog.getSprite().getPosition().x < -_frog.getSprite().getGlobalBounds().width / 2) {

				this->pauseMusic();
				_data->assets.getSound("Plunk").play();
				this->killFrog();
			}

			if (_levelTimer.getElapsedTime().asSeconds() > 25.0f && _timeWarning) {
				this->pauseMusic();
				_data->assets.getSound("Time").play();
				_timeWarning = false;
			}

			if (_levelTimer.getElapsedTime().asSeconds() > 30.0f) {
				this->pauseMusic();
				_data->assets.getSound("Squash").play();
				this->killFrog();
			}

			_hud.setTime((int)_levelTimer.getElapsedTime().asSeconds());

		}


		if (_frog.death() && _deathTimer.getElapsedTime().asSeconds() > 1.5f) {
			if (_resetGame) {
				if (!_gameOver) {
					this->changeMusic(GAME_OVER_MUSIC_FILEPATH);
					_gameOverTimer.restart();
					_gameOver = true;
				}
				if (_gameOverTimer.getElapsedTime().asSeconds() > 4.0f) {
					_frog.restart();
					this->init();
				}
				return;
			} else {
				_levelTimer.restart();
				_timeWarning = true;
				_frog.restart();
			}
		}

		
		if ((!_themeMusic && _musicTimer.getElapsedTime().asSeconds() > _musicDuration) || 
			(_data->music.getStatus() == sf::SoundSource::Status::Paused && _musicPauseTimer.getElapsedTime().asSeconds() > 1.5f)) {

			_data->music.openFromFile(THEME_MUSIC_FILEPATH);
			_data->music.play();
			_themeMusic = true;
		}



		_frog.update();


	}

	void GameState::draw(float interpolation) {

		_data->window.clear();

		_data->window.draw(_topBackground);


		//Draw grid lines
		/*float y = 0;
		for (int i = 0; i < SCREEN_HEIGHT / TILE_SIZE; i++) {

			_line[0] = sf::Vertex(sf::Vector2f(0.0, y));
			_line[1] = sf::Vertex(sf::Vector2f(SCREEN_WIDTH, y));

			y += TILE_SIZE;

			_data->window.draw(_line, 2, sf::Lines);
		}
		float x = 0;
		for (int i = 0; i < SCREEN_WIDTH / TILE_SIZE; i++) {

			_line[0] = sf::Vertex(sf::Vector2f(x, 0.0));
			_line[1] = sf::Vertex(sf::Vector2f(x, SCREEN_HEIGHT));

			x += TILE_SIZE;

			_data->window.draw(_line, 2, sf::Lines);
		}*/


		for (int i = 0; i < _pads.size(); i++) {
			_data->window.draw(_pads[i]);
		}

		for (int i = 0; i < _cars.size(); i++) {
			_cars[i]->draw();
		}

		for (int i = 0; i < _logs.size(); i++) {
			_logs[i]->draw();
		}

		for (int i = 0; i < _turtles.size(); i++) {
			_turtles[i]->draw();
		}

		for (int i = 0; i < _goalFrogs.size(); i++) {
			if (_goalsReached[i]) {
				_data->window.draw(_goalFrogs[i]);
			}
		}

		for (int i = 0; i < _hp.size(); i++) {
			_data->window.draw(_hp[i]);
		}

		if (!_win) {
			_frog.draw();
		}

		_hud.drawScore();
		_hud.drawHighScore();
		_hud.drawTime();

		_data->window.display();
	}


	void GameState::killFrog() {
		_frog.setDeath();
		_deathTimer.restart();
		_hud.saveHighScore();

		if (_hp.size() == 0) {
			_resetGame = true;
		} else {
			_hp.pop_back();
		}
	}

	void GameState::changeMusic(std::string filepath) {
		_data->music.openFromFile(filepath);
		_data->music.play();
		_musicDuration = _data->music.getDuration().asSeconds();
		_themeMusic = false;
		_musicTimer.restart();
	}

	void GameState::pauseMusic() {
		_data->music.pause();
		_musicPauseTimer.restart();
	}


}


