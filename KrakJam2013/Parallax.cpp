#include "pch.hpp"
#include "Parallax.hpp"

void Parallax::Load(std::vector<std::string> const & filenames,
        std::vector<float> const & speeds, sf::FloatRect _rect)
{
    assert(filenames.size());
    assert(filenames.size() == speeds.size());
    bool result;
    backgrounds.resize(filenames.size());
    for (int i = 0 ; i < filenames.size() ; ++i)
    {
        result = backgrounds[i].image.loadFromFile(filenames[i]);
        assert(result);
        backgrounds[i].speed = speeds[i];
    }
    rect = _rect;
    rect.width;
}

void Parallax::Load(std::vector<std::string> const & filenames, sf::FloatRect _rect)
{
    assert(filenames.size());
    bool result;
    float unitWidth;
    backgrounds.resize(filenames.size());
    for (int i = filenames.size() - 1 ; i >= 0 ; --i)
    {
        result = backgrounds[i].image.loadFromFile(filenames[i]);
        assert(result);
        if (i == filenames.size() - 1)
        {
            unitWidth = (float)backgrounds[i].image.getSize().x;
            backgrounds[i].speed = 1.0f;
        }
        else
        {
            backgrounds[i].speed = (float)backgrounds[i].image.getSize().x / unitWidth;
        }
    }
    rect = _rect;
}

void Parallax::Scroll(float dist)
{
    scrollDist = dist;
}

void Parallax::Render(void)
{
    float dist, rw2 = rect.width / 2.0f, w, f, right, diff;
    for (int i = 0 ; i < backgrounds.size() ; ++i)
    {
        w = (float)backgrounds[i].image.getSize().x;
        dist = scrollDist * backgrounds[i].speed;
        f = rw2 - dist;
        dist += w * (floor(f / w) + 1.0f);
        right = dist + rw2;
        sprite.setTexture(backgrounds[i].image);
        sprite.setPosition(rect.left, rect.top);
        if (right <= w)
        {
            sprite.setTextureRect(sf::IntRect(int(dist - rw2), 0,
                int(rect.width), int(rect.height)));
            window.draw(sprite);
        }
        else
        {
            diff = right - w;
            sprite.setTextureRect(sf::IntRect(int(dist - rw2), 0,
                int(rect.width - diff), int(rect.height)));
            window.draw(sprite);
            sprite.setPosition(rect.left + rect.width - diff, rect.top);
            sprite.setTextureRect(sf::IntRect(0, 0,
                int(diff + 0.5f), int(rect.height)));
            window.draw(sprite);
        }
    }
}
