#include "pch.hpp"
#include "Player.h"


Player::Player(sf::Vector2f startPos, sf::Vector2u windowSize, b2World *pWorld)
{
	_position = startPos;
	_windowSize = windowSize;

	b2BodyDef bDef;
	bDef.type = b2_dynamicBody;
}


Player::~Player()
{
}

void Player::update(float deltaTime)
{
	sf::Vector2f newPosition;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		newPosition.y = _position.y - _velocity.y * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		newPosition.y = _position.y + _velocity.y * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		newPosition.x = _position.x - _velocity.x * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		newPosition.x = _position.x + _velocity.x * deltaTime;

	_position.x = (newPosition.x < 0) ? 0 : newPosition.x;
	_position.x = (newPosition.x > _windowSize.x) ? _windowSize.x : _position.x;

	_position.y = (newPosition.y < 0) ? 0 : newPosition.y;
	_position.y = (newPosition.y > _windowSize.y) ? _windowSize.y : _position.y;
}