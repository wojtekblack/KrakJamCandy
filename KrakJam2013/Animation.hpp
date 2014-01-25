#pragma once

class Animation
{
    public:
    struct Sequence
    {
        std::string name;
        uint startFrame;
        uint endFrame;
    };

    enum Type
    {
        Forward,
        Reverse,
        ForwardAndReverse
    };

    private:
    sf::Texture spriteSheet;
    std::vector<sf::Sprite> frames;
    std::vector<Sequence> sequences;
    uint currentSeq;
    uint currentFrame;
    Type animType;
    uint playbackCount;   // 0 - infinity
    bool currentlyForward;
    bool playing;
    float2 position;
    float rotation;
    float2 scale;
    sf::Color color;
    uint frameDuration;
    uint currentDuration;
	uint frameWidth;
	uint frameHeight;

    public:
    void Load(std::string filename, uint frameCount, uint _frameDuration);
    void AddSequence(Sequence const & sequence);
    void PlaySequence(std::string name, Type _animType, uint _playbackCount);
    void Update(void);
    void Render(void);
    void SetPosition(float2 _position);
    void SetRotation(float _rotation);
    void SetScale(float _scale);
    void SetScale(float2 _scale);
    void SetColor(sf::Color _color);
	sf::Vector2u GetSize();
};
