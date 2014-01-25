#pragma once

#include "Screen.hpp"
#include <string>

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

	std::vector<Dot*> dots;

    public:
    void Load(void);
    void Init(void);
    void HandleEvent(sf::Event const & event);
    void Update(void);
    void Render(void);
    void Unload(void);

	void generateDots(int);

	static void debugPrint(std::stringstream);
};
