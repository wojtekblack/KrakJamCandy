#include "pch.hpp"
#include "PopupText.hpp"

PopupText::PopupText(void)
{
    font.loadFromFile("times.tff");
}

void PopupText::Load(Params const & params)
{
    bool result = font.loadFromFile(params.fontName);
    assert(result);
    size = params.size;
    assert(params.duration >= 0.0f);
    assert(params.distance >= 0.0f);
    text.setFont(font);
    text.setCharacterSize(params.size);
    text.setStyle(params.style);
    color = params.color;
    duration = params.duration;
    distance = params.distance;
    alphaFade = params.alphaFade;
}

void PopupText::Show(std::string _text, float2 position)
{
    Text text;
    text.text = _text;
    text.startPos = position;
    text.time = 0.0f;
    texts.push_back(text);
}

void PopupText::Update(void)
{
    float2 tmpPosition;
    for (int i = 0 ; i < texts.size() ; ++i)
    {
        if (texts[i].time >= duration)
        {
            texts.erase(texts.begin() + i);
            --i;
        }
        else
        {
            texts[i].time += ONE_SIXTIETH;
            if (texts[i].time >= duration)
            {
                texts[i].time = duration;
            }
            tmpPosition = texts[i].startPos;
            tmpPosition.y -= texts[i].time * distance / duration;
            texts[i].currentPos = tmpPosition;
            if (alphaFade)
            {
                texts[i].alpha = 255 - sf::Uint8(255 * texts[i].time / duration);
            }
        }
    }
}

void PopupText::Render(void)
{
    for (int i = 0 ; i < texts.size() ; ++i)
    {
        text.setPosition(texts[i].currentPos);
        color.a = texts[i].alpha;
        text.setColor(color);
        text.setString(texts[i].text);
        text.setOrigin(text.getGlobalBounds().width / 2.0f,
            text.getGlobalBounds().height);
        window.draw(text);
    }
}
