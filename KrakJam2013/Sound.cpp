#include "pch.hpp"
#include "Sound.hpp"

void Sound::Load(std::string filename)
{
    bool result = soundBuffer.loadFromFile(filename);
    assert(result);
}

void Sound::Update(void)
{
    while (soundInstances.size()
        && soundInstances.front().getStatus() == sf::Sound::Stopped)
    {
        soundInstances.pop_front();
    }
}

void Sound::Play(void)
{
    soundInstances.push_back(sf::Sound(soundBuffer));
    soundInstances.back().play();
}
