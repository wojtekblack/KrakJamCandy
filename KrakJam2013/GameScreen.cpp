#include "pch.hpp"
#include "Dot.hpp"
#include "GameScreen.hpp"
#include <sstream>
#include <string> 
#include <windows.h>
#include <iostream>

void GameScreen::Load(void)
{
    sampleText.setString("Hello world");
    arialFont.loadFromFile("data/arial.ttf");
    assert(monsterImage.loadFromFile("data/monster.png"));
    monster.Load(monsterImage, sf::Vector2f(100.0f, 200.0f));
	player.Load("data/player.png", 1, 5, world);

	b2Vec2 gravity(0.0f, 0.0f);
	world = new b2World(gravity);
}

void GameScreen::Init(void)
{
    sampleText.setFont(arialFont);
    sampleText.setString("Game Screen");
    sampleText.setCharacterSize(24);
    sampleText.setColor(sf::Color::Red);
    sampleText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    sampleText.setPosition(10.0f, 10.0f);

	player.Init(sf::Vector2f(400, 300), sf::Vector2f(50.f, 50.f));
	generateDots(5);
}

void GameScreen::HandleEvent(sf::Event const & event)
{
}

void GameScreen::Update(float deltaTime)
{
	player.Update(deltaTime);
    monster.Update(sf::Vector2f(400.0f, 300.0f));
}

void GameScreen::Render(void)
{
	player.Render();
    monster.Render();
    window.draw(sampleText);
}

void GameScreen::Unload(void)
{
}

void GameScreen::generateDots(int number)
{	
	for(int i=0; i<dots.size(); i++)
		delete dots[i];
	dots.clear();

	for(int i=0; i < number; i++){
		Dot *d = new Dot;
		d->init();
		dots.push_back(d);
	}
}

void GameScreen::debugPrint(std::stringstream stream)
{
	std::string str;
	std::getline(stream, str);

	OutputDebugStringA(str.c_str());
}