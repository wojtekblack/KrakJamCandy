#include "pch.hpp"
#include "Monster.hpp"

const float MONSTER_SPEED = 1.0f;

void Monster::Load(sf::Texture const & image, sf::Vector2f const & startPos)
{
    sprite.setTexture(image);
    sprite.setOrigin(image.getSize().x * 0.5f, image.getSize().y * 0.5f);
    sprite.setPosition(startPos);
}

void Monster::Update(sf::Vector2f const & targetPos)
{
    auto currentPos = sprite.getPosition();
    auto dir = targetPos - currentPos;
    sfm::Normalize(dir);
    sprite.setPosition(currentPos + dir * MONSTER_SPEED);
}

void Monster::Render(void)
{
    window.draw(sprite);
}
