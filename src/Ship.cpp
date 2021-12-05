#include "Ship.h"
#include <iostream>
using namespace std;

Ship::Ship()
{
	//initialize health and speed of ship
	health = 10;
	speed = 5;

	//initialize starting point of ship
	xLocation = 540;
	yLocation = 460;

	// set normal rotation facing right side
	angle = 0;
}

void Ship::RightRotation()
{
	angle = angle - 5;
}

void Ship::LeftRotation()
{
	angle = angle + 5;
}

void Ship::update()
{
	xLocation = xLocation + speed * cos(double(angle)*3.14159/180.0);
	yLocation = yLocation + speed * sin(double(angle)*3.14159/180.0);
}

void Ship::loseLives()
{
    health--;
}
