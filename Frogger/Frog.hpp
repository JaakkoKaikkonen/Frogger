#pragma once

#include <SFML\Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "Animation.hpp"
#include "HUD.hpp"

namespace Game {

	class Frog
	{
	public:
		Frog(gameDataRef data, HUD& hud);
		~Frog();

		void move(Dir dir);

		void update();

		void draw();

		void setDeath();

		void restart();

		bool death() { return _death; }

		sf::Sprite& getSprite() { return _frog; }

	private:
		gameDataRef _data;

		HUD& _hud;

		sf::Sprite _frog;

		Dir _dir;

		sf::Clock _jumpTimer;

		int _maxDistance = 15;

		const int _stepCount = 8;

		int _moveCount = 0;

		bool _death = false;

		sf::IntRect _jumpAnimationFrames[2] = { FROG_JUMP_01, FROG_JUMP_02 };

		Animation<2> _jumpAnimation;

		sf::IntRect _deathAnimationFrames[4] = { FROG_DEATH_01, FROG_DEATH_02, FROG_DEATH_03, FROG_DEATH_04 };

		Animation<4> _deathAnimation;

		sf::Clock _deathTimer;

	};

}

