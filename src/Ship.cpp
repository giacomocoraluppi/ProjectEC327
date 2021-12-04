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


int Ship::RightRotation()
{
	int RightRotation = xLocation * cosf(RightRotation) - yLocation * sinf(RightRotation);
	return RightRotation;
}

int Ship::LeftRotation()
{
	int LeftRotation = xLocation * sinf(LeftRotation) + yLocation * cosf(LeftRotation);
	return LeftRotation;
}
