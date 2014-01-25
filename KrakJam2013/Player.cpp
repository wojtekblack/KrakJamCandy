#include "pch.hpp"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::Init(sf::Vector2f initPos, sf::Vector2f initVel)
{
	_position = initPos;
	_velocity = initVel;

	Animation::Sequence sequence;
	sequence.name = "main";
	sequence.startFrame = 0;
	sequence.endFrame = 0;
	playerAnimation.AddSequence(sequence);

	playerAnimation.SetScale(1.0);
	playerAnimation.SetColor(sf::Color::Red);
}

void Player::Load(std::string filename, uint frameCount, uint frameDuration, b2World *pWorld)
{
	_windowSize = sf::Vector2u(800, 600);
	playerAnimation.Load(filename, frameCount, frameDuration);
}

void Player::Update()
{
	sf::Vector2f newPosition = _position;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		newPosition.y -= _velocity.y;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		newPosition.y += _velocity.y;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		newPosition.x -= _velocity.x;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
		//sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		newPosition.x += _velocity.x;

	_position.x = (newPosition.x < 0) ? 0 : newPosition.x;
	_position.x = (newPosition.x + playerAnimation.GetSize().x > _windowSize.x) ? _windowSize.x : _position.x;

	_position.y = (newPosition.y < 0) ? 0 : newPosition.y;
	_position.y = (newPosition.y + playerAnimation.GetSize().y > _windowSize.y) ? _windowSize.y : _position.y;

	_position = newPosition;

	playerAnimation.SetPosition(_position);
	playerAnimation.Update();
	playerAnimation.PlaySequence("main", Animation::Forward, 0);
}

void Player::Render()
{
	playerAnimation.Render();
}