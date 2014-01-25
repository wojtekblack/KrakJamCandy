#include "pch.hpp"
#include "Player.h"


Player::Player(sf::Vector2u windowSize)
{
	_windowSize = windowSize;
}


Player::~Player()
{
}

void Player::update(float deltaTime)
{
	sf::Vector2f newPosition;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		newPosition.y = _position.y - _velocity.y * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		newPosition.y = _position.y + _velocity.y * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		newPosition.x = _position.x - _velocity.x * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		newPosition.x = _position.x + _velocity.x * deltaTime;

	_position.x = (newPosition.x < 0) ? 0 : newPosition.x;
	_position.x = (newPosition.x > _windowSize.x) ? _windowSize.x : _position.x;

	_position.y = (newPosition.y < 0) ? 0 : newPosition.y;
	_position.y = (newPosition.y > _windowSize.y) ? _windowSize.y : _position.y;
}