#pragma once

#include "Screen.hpp"

class SampleScreen : public Screen
{
    private:
    Animation anim;
    Sound donkey;
    sf::Music music;
    PopupText popup;
    Parallax parallax;
    float scroll;

    public:
    void Load(void);
    void Init(void);
    void HandleEvent(sf::Event const & event);
    void Update(void);
    void Render(void);
    void Unload(void);
};
