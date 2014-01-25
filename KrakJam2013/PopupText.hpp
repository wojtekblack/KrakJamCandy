#pragma once

class PopupText
{
    public:
    struct Params
    {
        std::string fontName;
        uint size;
        sf::Text::Style style;
        sf::Color color;
        float duration;
        float distance;
        bool alphaFade;
    };

    private:
    struct Text
    {
        std::string text;
        float2 startPos;
        float2 currentPos;
        sf::Uint8 alpha;
        float time;
    };

    sf::Font font;
    sf::Text text;
    std::vector<Text> texts;
    uint size;
    sf::Color color;
    float duration;
    float distance;
    bool alphaFade;

    public:
    PopupText(void);
    void Load(Params const & params);
    void Show(std::string text, float2 position);
    void Update(void);
    void Render(void);
};
