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
	int leftRotation = 0;
	int rightRotation = 90;
}

int Ship::RightRotation()
{
	int rightRotation = xLocation * cosf(rightRotation) - yLocation * sinf(rightRotation);
	return rightRotation;
}

int Ship::LeftRotation()
{
	int leftRotation = xLocation * sinf(leftRotation) + yLocation * cosf(leftRotation);
	return leftRotation;
}
