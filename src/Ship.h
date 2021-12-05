#ifndef SHIP
#define SHIP
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class Ship
{
public: 
	int health;
	int speed;
	int xLocation;
	int yLocation;
	int angle;

	Ship();
	int LeftRotation();
	int RightRotation();
	void update();
	int loseLives();
};

#endif
