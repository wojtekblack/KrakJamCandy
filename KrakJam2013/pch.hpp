#pragma once

#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <cassert>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "RixMath.hpp"
#include "Miscellaneous.hpp"
#include "ScreenManager.hpp"
#include "Sound.hpp"
#include "Animation.hpp"
#include "PopupText.hpp"
#include "Parallax.hpp"

#include <Box2D\Box2D.h>

#pragma warning(disable : 4018)

class MenuScreen;
class SampleScreen;
class GameScreen;

extern sf::RenderWindow window;
extern ScreenManager screenManager;
extern SampleScreen sampleScreen;
extern MenuScreen menuScreen;
extern GameScreen gameScreen;
extern const float ONE_SIXTIETH;
