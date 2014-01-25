#pragma once
class Player
{
	sf::Vector2f _position;
	sf::Vector2f _velocity;
	sf::Vector2u _windowSize;

public:

	Animation playerAnimation;

	Player(sf::Vector2u windowSize);
	~Player();

	void update(float deltaTime);

};

