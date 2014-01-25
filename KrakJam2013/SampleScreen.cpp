#include "pch.hpp"
#include "SampleScreen.hpp"

void SampleScreen::Load(void)
{
    anim.Load("data/test_anim.png", 16, 4);
    donkey.Load("data/donkey.ogg");
    bool result = music.openFromFile("data/bongo.wav");
    assert(result);
    PopupText::Params params;
    params.fontName = "data/times.ttf";
    params.size = 35;
    params.style = sf::Text::Italic;
    params.color = sf::Color(255, 0, 0);
    params.duration = 1.0f;
    params.distance = 30.0f;
    params.alphaFade = true;
    popup.Load(params);
    std::vector<std::string> images;
    images.push_back("data/parallax_0.png");
    images.push_back("data/parallax_1.png");
    images.push_back("data/parallax_2.png");
    images.push_back("data/parallax_3.png");
    images.push_back("data/parallax_4.png");
    parallax.Load(images, sf::FloatRect(0.0f, 0.0f, 800.0f, 600.0f));
}

void SampleScreen::Init(void)
{
    Animation::Sequence sequence;
    sequence.name = "theOnlyOne";
    sequence.startFrame = 0;
    sequence.endFrame = 15;
    anim.AddSequence(sequence);
    anim.SetPosition(float2(100.0f, 100.0f));
    anim.SetRotation(float(0.0f));
    anim.SetScale(1.0f);
    anim.SetColor(sf::Color(255, 255, 255));
    anim.PlaySequence("theOnlyOne", Animation::ForwardAndReverse, 0);
    music.setLoop(true);
    music.play();
    scroll = 0.0f;
}

void SampleScreen::HandleEvent(sf::Event const & event)
{
    if (event.type == sf::Event::MouseButtonPressed
        && event.mouseButton.button == sf::Mouse::Left)
    {
        donkey.Play();
        popup.Show("SiEmA", float2((float)sf::Mouse::getPosition(window).x,
            (float)sf::Mouse::getPosition(window).y));
    }
}

void SampleScreen::Update(void)
{
    //bool         LeftKeyDown     = input.IsKeyDown(sf::Key::Left);
    //bool         RightButtonDown = input.IsMouseButtonDown(sf::Mouse::Right);
    //bool         JoyButton1Down  = input.IsJoystickButtonDown(0, 1);
    //unsigned int MouseX          = input.getMouseX();
    //unsigned int MouseY          = input.getMouseY();
    //float        JoystickX       = input.getJoystickAxis(1, sf::Joy::AxisZ);
    //float        JoystickY       = input.getJoystickAxis(1, sf::Joy::AxisY);
    //float        JoystickPOV     = input.getJoystickAxis(1, sf::Joy::AxisPOV);

    anim.Update();
    donkey.Update();
    popup.Update();
    scroll += 1.0f;
    parallax.Scroll(scroll);
}

void SampleScreen::Render(void)
{
    parallax.Render();
    anim.Render();
    popup.Render();
}

void SampleScreen::Unload(void)
{
}
