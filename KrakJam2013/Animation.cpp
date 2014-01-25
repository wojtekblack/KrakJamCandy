#include "pch.hpp"
#include "Animation.hpp"

void Animation::Load(std::string filename, uint frameCount, uint _frameDuration)
{
    assert(frameCount);
    assert(_frameDuration);
    bool result = spriteSheet.loadFromFile(filename);
    assert(result);
    frameWidth = spriteSheet.getSize().x / frameCount;
    assert(frameWidth * frameCount == spriteSheet.getSize().x);
    frameHeight = spriteSheet.getSize().y;
    frames.resize(frameCount);
    for (int i = 0 ; i < frameCount ; ++i)
    {
        frames[i].setTexture(spriteSheet);
        frames[i].setTextureRect(sf::IntRect(i * frameWidth, 0, frameWidth, frameHeight));
        frames[i].setOrigin(frameWidth / 2.0f, frameHeight / 2.0f);
    }
    frameDuration = _frameDuration;
}

void Animation::AddSequence(Sequence const & sequence)
{
    assert(sequence.startFrame <= sequence.endFrame);
    assert(sequence.startFrame < frames.size());
    assert(sequence.endFrame < frames.size());
    sequences.push_back(sequence);
}

void Animation::PlaySequence(std::string name, Type _animType, uint _playbackCount)
{
    bool sequenceExists = false;
    for (int i = 0 ; i < sequences.size() ; ++i)
    {
        if (sequences[i].name == name)
        {
            currentSeq = i;
            sequenceExists = true;
            break;
        }
    }
    assert(sequenceExists);
    currentFrame = sequences[currentSeq].startFrame;
    playing = currentFrame != sequences[currentSeq].endFrame;
    animType = _animType;
    playbackCount = _playbackCount;
    if (animType == ForwardAndReverse)
    {
        currentlyForward = true;
    }
    currentDuration = 0;
}

void Animation::Update(void)
{
    if (playing)
    {
        switch (animType)
        {
            case Forward:
                if (currentFrame < sequences[currentSeq].endFrame)
                {
                    ++currentDuration;
                    if (currentDuration == frameDuration)
                    {
                        currentDuration = 0;
                        ++currentFrame;
                    }
                }
                if (currentFrame == sequences[currentSeq].endFrame)
                {
                    currentFrame = sequences[currentSeq].startFrame;
                    if (playbackCount)
                    {
                        --playbackCount;
                        if (playbackCount == 0)
                        {
                            playing = false;
                        }
                    }
                }
                break;
            case Reverse:
                if (currentFrame > sequences[currentSeq].startFrame)
                {
                    ++currentDuration;
                    if (currentDuration == frameDuration)
                    {
                        currentDuration = 0;
                        --currentFrame;
                    }
                }
                if (currentFrame == sequences[currentSeq].startFrame)
                {
                    currentFrame = sequences[currentSeq].endFrame;
                    if (playbackCount)
                    {
                        --playbackCount;
                        if (playbackCount == 0)
                        {
                            playing = false;
                        }
                    }
                }
                break;
            case ForwardAndReverse:
                if (currentlyForward)
                {
                    if (currentFrame < sequences[currentSeq].endFrame)
                    {
                        ++currentDuration;
                        if (currentDuration == frameDuration)
                        {
                            currentDuration = 0;
                            ++currentFrame;
                        }
                    }
                    if (currentFrame == sequences[currentSeq].endFrame)
                    {
                        currentlyForward = false;
                    }
                }
                else
                {
                    if (currentFrame > sequences[currentSeq].startFrame)
                    {
                        ++currentDuration;
                        if (currentDuration == frameDuration)
                        {
                            currentDuration = 0;
                            --currentFrame;
                        }
                    }
                    if (currentFrame == sequences[currentSeq].startFrame)
                    {
                        currentlyForward = true;
                        currentFrame = sequences[currentSeq].startFrame;
                        if (playbackCount)
                        {
                            --playbackCount;
                            if (playbackCount == 0)
                            {
                                playing = false;
                            }
                        }
                    }
                }
                break;
        }
    }
}

void Animation::Render(void)
{
    frames[currentFrame].setPosition(position);
    frames[currentFrame].setRotation(rotation);
    frames[currentFrame].setScale(scale);
    frames[currentFrame].setColor(color);
    window.draw(frames[currentFrame]);
}

void Animation::SetPosition(float2 _position)
{
    position = _position;
}

void Animation::SetRotation(float _rotation)
{
    rotation = _rotation;
}

void Animation::SetScale(float _scale)
{
    scale = float2(_scale, _scale);
}

void Animation::SetScale(float2 _scale)
{
    scale = _scale;
}

void Animation::SetColor(sf::Color _color)
{
    color = _color;
}

sf::Vector2u Animation::GetSize()
{
	return sf::Vector2u(frameWidth, frameHeight);
}
