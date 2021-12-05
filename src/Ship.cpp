#include "Ship.h"
#include <iostream>
using namespace std;

Ship::Ship()
{
	//initialize health and speed of ship
	int health = 10;
	int speed = 5;

	//initialize starting point of ship
	int xLocation = 540;
	int yLocation = 460;

	// set normal rotation facing right side
	int angle = 0;
}

int Ship::RightRotation()
{
	angle = angle - 5;
	return angle;
}

int Ship::LeftRotation()
{
	angle = angle + 5;
	return angle;
}

void Ship::update()
{
	xLocation = xLocation + speed * cos(double(angle)*3.14159/180.0);
	yLocation = yLocation + speed * sin(double(angle)*3.14159/180.0);
}

int Ship::loseLives()
{
    health--;
    return health;
}
