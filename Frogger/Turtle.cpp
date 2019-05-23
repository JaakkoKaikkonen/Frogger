#include "Turtle.hpp"

namespace Game {

	Turtle::Turtle(gameDataRef data, const int& x, const int& y)
		: _data(data), _turtle(_data->assets.getTexture("Turtle"), TURTLE_01), _swimAnimation(&_turtle, _swimAnimationFrames, 0.75f)
	{
		_turtle.setOrigin(_turtle.getGlobalBounds().width / 2, _turtle.getGlobalBounds().height / 2);
		_turtle.setScale(3.0f, 3.0f);
		_turtle.setPosition((float)x, (float)y);
	}


	void Turtle::move() {

		_turtle.move(_speed, 0.0f);
		
		if (_turtle.getPosition().x < -TILE_SIZE) {
			_turtle.setPosition(SCREEN_WIDTH + TILE_SIZE, _turtle.getPosition().y);
		}

	}

	void Turtle::draw() {
		_swimAnimation.animate();
		_data->window.draw(_turtle);
	}


}