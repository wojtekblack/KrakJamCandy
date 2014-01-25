#include "pch.hpp"
#include "ScreenManager.hpp"

void ScreenManager::AddScreen(Screen & screen)
{
    screens.push_back(&screen);
}

void ScreenManager::Load(void)
{
    for (int i = 0 ; i < screens.size() ; ++i)
    {
        screens[i]->Load();
    }
}

void ScreenManager::SetCurrentScreen(Screen const & screen)
{
    auto it = std::find(screens.begin(), screens.end(), &screen);
    assert(it != screens.end());
    currentScreen = it;
}

void ScreenManager::Init(void)
{
    (*currentScreen)->Init();
}

void ScreenManager::HandleEvent(sf::Event const & event)
{
    (*currentScreen)->HandleEvent(event);
}

void ScreenManager::Update(void)
{
    (*currentScreen)->Update();
}

void ScreenManager::Render(void)
{
    (*currentScreen)->Render();
}

void ScreenManager::Unload(void)
{
    for (int i = 0 ; i < screens.size() ; ++i)
    {
        screens[i]->Unload();
    }
}
