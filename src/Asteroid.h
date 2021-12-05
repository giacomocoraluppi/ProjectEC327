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
	int xLocation;
	int yLocation;
	double xTraj;
	double yTraj;

	Asteroid();
	void update();
	int loseLives();
};
	
#endif
