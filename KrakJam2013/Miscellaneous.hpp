#pragma once

typedef unsigned int uint;
typedef sf::Vector2<int> int2;
typedef sf::Vector2<float> float2;
typedef sf::Vector3<int> int3;
typedef sf::Vector3<float> float3;

template <typename T>
inline T Clamp(T const & what, T const & a, T const & b)
{
    return std::min(b, std::max(what, a));
}

inline void SetPivotCenter(sf::Sprite & sprite)
{
    sprite.setOrigin(sprite.getTexture()->getSize().x / 2.0f,
        sprite.getTexture()->getSize().y / 2.0f);
}
