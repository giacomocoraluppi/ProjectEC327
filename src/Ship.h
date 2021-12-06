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
	float xLocation;
	float yLocation;
	float angle;

	Ship();
	void LeftRotation();
	void RightRotation();
	void WPressed();
	void SPressed();
	void update();
	void loseLives();
};

#endif
