#pragma once

#include "Screen.hpp"
#include "Monster.hpp"

class GameScreen : public Screen
{
    private:
    sf::Text sampleText;
    sf::Font arialFont;
    sf::Texture monsterImage;
    Monster monster;

    public:

	b2World *world;

    void Load(void);
    void Init(void);
    void HandleEvent(sf::Event const & event);
    void Update(void);
    void Render(void);
    void Unload(void);
};