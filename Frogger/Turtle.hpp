#pragma once

#include <SFML\Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "Animation.hpp"

namespace Game {

	class Turtle
	{
	public:
		Turtle(gameDataRef data, const int& x, const int& y);

		void move();

		void draw();

		sf::Sprite& getSprite() { return _turtle; }

		float& getSpeed() { return _speed; }

	private:
		gameDataRef _data;

		sf::Sprite _turtle;

		sf::IntRect _swimAnimationFrames[3] = { TURTLE_01, TURTLE_02, TURTLE_03 };

		Animation<3> _swimAnimation;

		float _speed = -2.0f;
	};

}

