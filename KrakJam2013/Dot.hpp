#pragma once

#include <math.h>
#include <iostream>
#include "GameScreen.hpp"

class Dot 
{
public:
	enum GameColours colour;

	double posX;
	double posY;
	double value;

	Dot();

	void init();
	void collect();
	void update();
};