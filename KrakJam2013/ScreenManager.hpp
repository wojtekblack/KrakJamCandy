#pragma once

#include "Screen.hpp"

class ScreenManager
{
    private:
    std::vector<Screen *> screens;
    std::vector<Screen *>::iterator currentScreen;

    public:
    void AddScreen(Screen & screen);
    void Load(void);
    void SetCurrentScreen(Screen const & screen);
    void Init(void);
    void HandleEvent(sf::Event const & event);
    void Update();
    void Render(void);
    void Unload(void);
};
