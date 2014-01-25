#include "pch.hpp"
#include <math.h>
#include "Dot.hpp"
#include <sstream>
#include <string> 
#include <windows.h>
#include <iostream>

Dot::Dot()
{

}

void Dot::init()
{	
	colour = static_cast<GameColours>(rand() % GameColoursSIZE);

}

void Dot::collect()
{
	init();
}

void Dot::update()
{

}