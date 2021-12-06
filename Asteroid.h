#ifndef ASTEROID
#define ASTEROID
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class Asteroid
{
public:
	int health;
	int speed;
	float xLocation;
	float yLocation;
	float xTraj;
	float yTraj;

	Asteroid();
	void update();
	void loseLives();
};
	
#endif
