#pragma once

#include "Screen.hpp"

class GameScreen : public Screen
{
    private:
    sf::Text sampleText;
    sf::Font arialFont;

    public:
    void Load(void);
    void Init(void);
    void HandleEvent(sf::Event const & event);
    void Update(void);
    void Render(void);
    void Unload(void);
};