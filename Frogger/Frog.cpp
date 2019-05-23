#include "Frog.hpp"
#include <iostream>

namespace Game {

	Frog::Frog(gameDataRef data, HUD& hud)
		: _data(data), _hud(hud), _frog(_data->assets.getTexture("Frog"), FROG_IDLE), 
		_jumpAnimation(&_frog, _jumpAnimationFrames, 0.1f), _deathAnimation(&_frog, _deathAnimationFrames, 1.0f)
	{
		_frog.setOrigin(_frog.getGlobalBounds().width / 2, _frog.getGlobalBounds().height / 2);
		_frog.setScale(3.0f, 3.0f);
		_frog.setPosition(SCREEN_WIDTH / 2 + TILE_SIZE / 2, SCREEN_HEIGHT - TILE_SIZE / 2 - TILE_SIZE);
	}


	void Frog::move(Dir dir) {

		if (_jumpTimer.getElapsedTime().asSeconds() > 0.2f) {

			_data->assets.getSound("Jump").play();

			_dir = dir;
			_moveCount = _stepCount;

			if (Dir::Up == dir) {
				if ((int)_frog.getPosition().y / TILE_SIZE < _maxDistance) {
					_hud.addToScore(10);
					_maxDistance = (int)_frog.getPosition().y / TILE_SIZE;
				}
				_frog.setRotation(0.0f);
			} else if (Dir::Down == dir) {
				_frog.setRotation(180.0f);
			} else if (Dir::Right == dir) {
				_frog.setRotation(90.0f);
			} else if (Dir::Left == dir) {
				_frog.setRotation(-90.0f);
			}

			_jumpTimer.restart();

		}
	}

	void Frog::update() {

		if (_moveCount > 0) {
			if (Dir::Up == _dir) {
				_frog.move(0.0f, (float)-TILE_SIZE / _stepCount);
			} else if (Dir::Down == _dir) {
				_frog.move(0.0f, (float)TILE_SIZE / _stepCount);
			} else if (Dir::Right == _dir) {
				_frog.move((float)TILE_SIZE / _stepCount, 0.0f);
			} else if (Dir::Left == _dir) {
				_frog.move((float)-TILE_SIZE / _stepCount, 0.0f);
			}
			_moveCount--;

		}

	}

	void Frog::draw() {
		if (_death) {
			if (_deathTimer.getElapsedTime().asSeconds() < 0.7f) {
				_deathAnimation.animate();
			}
		} else if (_moveCount > 0) {
			_jumpAnimation.animate();
		} else {
			_frog.setTextureRect(FROG_IDLE);
			_jumpAnimation.reset();
		}

		_data->window.draw(_frog);
	}

	void Frog::setDeath() {
		_death = true;
		_frog.setTexture(_data->assets.getTexture("Death"));
		_frog.setTextureRect(FROG_DEATH_01);
		_frog.setRotation(0.0f);
		_maxDistance = 15;
		_deathTimer.restart();
	}

	

	void Frog::restart() {
		_death = false;
		_frog.setPosition(SCREEN_WIDTH / 2 + TILE_SIZE / 2, SCREEN_HEIGHT - TILE_SIZE / 2 - TILE_SIZE);
		_frog.setTexture(_data->assets.getTexture("Frog"));
		_frog.setTextureRect(FROG_IDLE);
		_deathAnimation.reset();
		_maxDistance = 15;
		_moveCount = 0;
	}


}