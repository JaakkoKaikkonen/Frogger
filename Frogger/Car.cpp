#include "Car.hpp"

namespace engine {


	Car::Car(gameDataRef data, sf::IntRect textureRect, const int& x, const int& y)
		: _data(data), _car(_data->assets.getTexture("Cars"), textureRect)
	{
		_car.setOrigin(_car.getGlobalBounds().width / 2, _car.getGlobalBounds().height / 2);
		_car.setScale(3.0f, 3.0f);
		_car.setPosition((float)x, (float)y);

		if (textureRect == CAR_02 || textureRect == CAR_04) {
			_dir = Dir::Right;
		} else {
			_dir = Dir::Left;
		}

		if (textureRect == CAR_04) {
			_speed = 5.0f;
		}

	}


	Car::~Car()
	{
	}


	void Car::move() {
		if (Dir::Right == _dir) {
			_car.move(_speed, 0.0f);
			if (_car.getPosition().x > SCREEN_WIDTH + TILE_SIZE) {
				_car.setPosition(-TILE_SIZE, _car.getPosition().y);
			}
		} else {
			_car.move(-_speed, 0.0f);
			if (_car.getPosition().x < -TILE_SIZE) {
				_car.setPosition(SCREEN_WIDTH + TILE_SIZE, _car.getPosition().y);
			}
		}

	}

	void Car::draw() {
		_data->window.draw(_car);
	}

}