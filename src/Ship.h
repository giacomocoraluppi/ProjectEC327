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

	Ship();
	int LeftRotation();
	int RightRotation();
	int getxLocation();
	int getyLocation();
};

#endif
