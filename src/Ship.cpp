# include <iostream>

#include "Ship.h"

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
	int LeftRotation = 0;
	int RightRotation = 90;

}


void Ship::RightRotation()
{
	RightRotation = xLocation * cosf(RightRotation) - yLocation * sinf(RightRotation);
}

void Ship::LeftRotation()
{
	LeftRotation = xLocation * sinf(LeftRotation) + yLocation * cosf(LeftRotation);
}