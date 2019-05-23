#pragma once

#include <SFML\Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Game {

	class Car
	{
	public:
		Car(gameDataRef data, sf::IntRect textureRect, const int& x, const int& y);

		void move();

		void draw();

		sf::Sprite& getSprite() { return _car; }

	private:
		gameDataRef _data;

		sf::Sprite _car;

		Dir _dir;

		float _speed = 2.0f;
	};


}

