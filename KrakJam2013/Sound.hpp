#pragma once

class Sound
{
    private:
    sf::SoundBuffer soundBuffer;
    std::deque<sf::Sound> soundInstances;

    public:
    void Load(std::string filename);
    void Update(void);
    void Play(void);
};
