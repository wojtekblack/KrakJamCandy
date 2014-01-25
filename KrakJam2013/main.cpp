#include "pch.hpp"
#include "SampleScreen.hpp"
#include "MenuScreen.hpp"
#include "GameScreen.hpp"

sf::RenderWindow window;
ScreenManager screenManager;
SampleScreen sampleScreen;
MenuScreen menuScreen;
GameScreen gameScreen;
const float ONE_SIXTIETH = 1.0f / 60.0f;

int main(void)
{
    screenManager.AddScreen(sampleScreen);
    screenManager.AddScreen(menuScreen);
    screenManager.AddScreen(gameScreen);
    screenManager.SetCurrentScreen(sampleScreen);
    screenManager.Load();
    screenManager.Init();
    window.create(sf::VideoMode(800, 600, 32), "SFML Framework",
        sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    sf::Clock clock;
    float dt = 0.0f;
    float lastUpdateTime = clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;
    const float MAX_ACCUMULATED_TIME = 1.0f;
    while (window.isOpen())
    {
        dt = clock.getElapsedTime().asSeconds() - lastUpdateTime;
        lastUpdateTime += dt;
        dt = std::max(0.0f, dt);
        accumulator += dt;
        accumulator = Clamp(accumulator, 0.0f, MAX_ACCUMULATED_TIME);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else
            {
                screenManager.HandleEvent(event);
            }
        }
        while (accumulator > ONE_SIXTIETH)
        {
            screenManager.Update();
            accumulator -= ONE_SIXTIETH;
        }
        window.clear(sf::Color(0, 0, 0));
        screenManager.Render();
        window.display();
    }
    screenManager.Unload();
    return EXIT_SUCCESS;
}
