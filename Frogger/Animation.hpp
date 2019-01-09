#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

template<int size>
class Animation
{
public:
	Animation();
	Animation(sf::Sprite* sprite, sf::IntRect animationFrames[size], float animationTime);

	void init(sf::Sprite* sprite, sf::IntRect animationFrames[size], float animationTime);

	void animate();

	void reset() { _animationiterator = 0; }

private:
	sf::Clock _clock;

	sf::Sprite* _sprite = nullptr;

	sf::IntRect* _animationFrames = nullptr;

	float _animationTime;

	unsigned int _animationiterator = 0;
};


template<int size>
Animation<size>::Animation() {}

template<int size>
Animation<size>::Animation(sf::Sprite* sprite, sf::IntRect animationFrames[size], float animationTime)
	: _sprite(sprite), _animationFrames(animationFrames), _animationTime(animationTime)
{
}

template<int size>
void Animation<size>::init(sf::Sprite* sprite, sf::IntRect animationFrames[size], float animationTime) {
	_sprite = sprite;
	_animationFrames = animationFrames;
	_animationTime = animationTime;
}

template<int size>
void Animation<size>::animate() {
	if (_clock.getElapsedTime().asSeconds() > _animationTime / size) {
		if (_animationiterator < size - 1) {
			_animationiterator++;
		} else {
			_animationiterator = 0;
		}
		_sprite->setTextureRect(_animationFrames[_animationiterator]);
		_clock.restart();
	}
}

