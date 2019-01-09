#include "Log.hpp"

namespace engine {

	Log::Log(gameDataRef data, sf::IntRect textureRect, const int& x, const int& y)
		: _data(data), _log(_data->assets.getTexture("Logs"), textureRect)
	{
		_log.setOrigin(_log.getGlobalBounds().width / 2, _log.getGlobalBounds().height / 2);
		_log.setScale(3.0f, 3.0f);
		_log.setPosition((float)x, (float)y);

		if (textureRect == LOG_03) {
			_speed = 3.0f;
		}
	}


	Log::~Log()
	{
	}


	void Log::move() {
		_log.move(_speed, 0.0f);

		if (_log.getPosition().x > SCREEN_WIDTH + _log.getGlobalBounds().width / 2) {
			_log.setPosition(-_log.getGlobalBounds().width, _log.getPosition().y);
		}
	}

	void Log::draw() {
		_data->window.draw(_log);
	}

}