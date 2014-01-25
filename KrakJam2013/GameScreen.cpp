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
}

void GameScreen::Init(void)
{
    sampleText.setFont(arialFont);
    sampleText.setString("Game Screen");
    sampleText.setCharacterSize(24);
    sampleText.setColor(sf::Color::Red);
    sampleText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    sampleText.setPosition(10.0f, 10.0f);

	generateDots(5);
}

void GameScreen::HandleEvent(sf::Event const & event)
{
}

void GameScreen::Update(void)
{
}

void GameScreen::Render(void)
{
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
