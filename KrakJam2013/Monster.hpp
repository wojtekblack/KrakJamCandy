#pragma once

class Monster
{
    private:
    sf::Texture image;
    sf::Sprite sprite;

    public:
    void Load(sf::Texture const & image, sf::Vector2f const & startPos);
    void Update(sf::Vector2f const & targetPos);
    void Render(void);
};
