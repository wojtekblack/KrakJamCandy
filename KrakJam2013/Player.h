#pragma once
class Player
{
	sf::Vector2f _position;
	sf::Vector2f _velocity;
	sf::Vector2u _windowSize;


public:

	Animation playerAnimation;

	Player(sf::Vector2f startPos, sf::Vector2u windowSize, b2World *pWorld);
	~Player();

	void update(float deltaTime);

};

