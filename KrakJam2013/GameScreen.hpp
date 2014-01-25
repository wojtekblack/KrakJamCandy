#pragma once

#include "Screen.hpp"
#include <string>
#include "Monster.hpp"
#include "Player.h"

class Dot;

enum GameColours
{
	RED = 0,
	GREEN,
	YELLOW,
	GameColoursSIZE
};

class GameScreen : public Screen
{
    private:
    sf::Text sampleText;
    sf::Font arialFont;
    sf::Texture monsterImage;
    Monster monster;
	Player player;

	std::vector<Dot*> dots;

    public:

	b2World *world;

    void Load(void);
    void Init(void);
    void HandleEvent(sf::Event const & event);
    void Update();
    void Render(void);
    void Unload(void);

	void generateDots(int);

	static void debugPrint(std::stringstream);
};