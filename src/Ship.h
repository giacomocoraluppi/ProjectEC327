#ifndef SHIP_H
#define SHIP_H

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>


class Ship
{

public: 
	int health;
	int xLocation;
	int yLocation;
	int LeftRotation();
	int RightRotation();
	int speed;


	Ship();
	~Ship();
};

#endif