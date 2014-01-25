#pragma once
class Player
{
	sf::Vector2f _position;
	sf::Vector2f _velocity;
	sf::Vector2u _windowSize;


public:

	Animation playerAnimation;

	Player();
	~Player();

	void Update();
	void Render();
	void Load(std::string filename, uint frameCount, uint frameDuration, b2World *pWorld);
	void Init(sf::Vector2f startPos, sf::Vector2f initVel);

};

