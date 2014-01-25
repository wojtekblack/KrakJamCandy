#pragma once

class Parallax
{
    private:
    struct Background
    {
        sf::Texture image;
        float speed;   // 0.0 - 1.0
    };

    std::vector<Background> backgrounds;
    sf::Sprite sprite;
    float scrollDist;
    sf::FloatRect rect;

    public:
    void Load(std::vector<std::string> const & filenames,
        std::vector<float> const & speeds, sf::FloatRect _rect);
    void Load(std::vector<std::string> const & filenames, sf::FloatRect _rect);
    void Scroll(float dist);
    void Render(void);
};
