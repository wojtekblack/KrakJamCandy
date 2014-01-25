#include "pch.hpp"
#include "MenuScreen.hpp"

void MenuScreen::Load(void)
{
    sampleText.setString("Hello world");
    timesFont.loadFromFile("data/arial.ttf");
}

void MenuScreen::Init(void)
{
    sampleText.setFont(timesFont);
    sampleText.setString("Menu Screen");
    sampleText.setCharacterSize(24);
    sampleText.setColor(sf::Color::White);
    sampleText.setPosition(10.0f, 10.0f);
}

void MenuScreen::HandleEvent(sf::Event const & event)
{
}

void MenuScreen::Update(void)
{
}

void MenuScreen::Render(void)
{
    window.draw(sampleText);
}

void MenuScreen::Unload(void)
{
}