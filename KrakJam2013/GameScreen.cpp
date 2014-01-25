#include "pch.hpp"
#include "GameScreen.hpp"

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