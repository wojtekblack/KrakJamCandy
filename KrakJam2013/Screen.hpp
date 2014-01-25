#pragma once

class Screen
{
    public:
    virtual void Load(void) = 0;
    virtual void Init(void) = 0;
    virtual void HandleEvent(sf::Event const & event) = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render(void) = 0;
    virtual void Unload(void) = 0;
};
