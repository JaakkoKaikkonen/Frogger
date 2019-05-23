#pragma once

#include <SFML\Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Game {

	class Log
	{
	public:
		Log(gameDataRef data, sf::IntRect textureRect, const int& x, const int& y);

		void move();

		void draw();

		sf::Sprite& getSprite() { return _log; }

		float& getSpeed() { return _speed; }

	private:
		gameDataRef _data;

		sf::Sprite _log;

		float _speed = 2.0f;
	};

}

