#include "Ship.h"
#include <iostream>
using namespace std;

Ship::Ship()
{
	//initialize health and speed of ship
	health = 3;
	moveSpeed = 2;
	rotationSpeed = 2.5;

	//initialize starting point of ship
	xLocation = 460;
	yLocation = 540;

	// set normal rotation facing right side
	angle = 90;
}

void Ship::RightRotation()
{
	angle = angle - rotationSpeed;
}

void Ship::LeftRotation()
{
	angle = angle + rotationSpeed;
}

void Ship::WPressed() {
	xLocation = xLocation + (moveSpeed * cos(double(angle - 90)*3.14159 / 180.0));
	yLocation = yLocation + (moveSpeed * sin(double(angle - 90)*3.14159 / 180.0));

	if (xLocation < 350) {
		xLocation = 350;
	}
	else if (xLocation > 1900) {
		xLocation = 1900;
	}
	if (yLocation < -10) {
		yLocation = 1080;
	}
	else if (yLocation > 1085) {
		yLocation = 0;
	}

	return;
}

void Ship::SPressed() {
	xLocation = xLocation - (moveSpeed * cos(double(angle - 90)*3.14159 / 180.0));
	yLocation = yLocation - (moveSpeed * sin(double(angle - 90)*3.14159 / 180.0));

	if (xLocation < 350) {
		xLocation = 350;
	}
	else if (xLocation > 1900) {
		xLocation = 1900;
	}
	if (yLocation < -10) {
		yLocation = 1080;
	}
	else if (yLocation > 1085) {
		yLocation = 0;
	}

	return;
}

void Ship::update()
{
	return;
}

void Ship::loseLives(int damage)
{
    health = health - damage;
}
