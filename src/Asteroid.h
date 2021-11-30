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
	int xLocation;
	int yLocation;
	double xTraj;
	double yTraj;
	int health;
	int speed;
	
	Asteroid();
	void update();
};
	
#endif
