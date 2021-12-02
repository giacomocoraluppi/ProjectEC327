#include "Asteroid.h"
#include <iostream>
using namespace std;

Asteroid::Asteroid()
{
	//declaration of variables given screen size of 920 x 1080 pixels
	int xSpawnMax = 1920;
	int xSpawnMin = xSpawnMax / 2;
	int ySpawnMax = 1080;
	int ySpawnMin = 0;
	int yDestMax = ySpawnMax * 3 / 4;
	int yDestMin = ySpawnMax * 1 / 4;
	
	//intialize random seed
	srand(time(NULL));
	
	int random = rand() % 4;
	
	int xSpawn;
	int ySpawn;
	//getting location where asteroid is spawning from
	if (random == 0 || random == 1)
	{
		//asteroid comes from right side of screen
		xSpawn = xSpawnMax;
		ySpawn = rand() % (ySpawnMax - ySpawnMin) + ySpawnMin;
	}
	else if (random == 2)
	{
		//asteroid comes from top side of screen
		xSpawn = rand() % (xSpawnMax - xSpawnMin) + xSpawnMin;
		ySpawn = ySpawnMax;
	}
	else if (random == 3)
	{
		//asteroid comes from bottom side of screen
		xSpawn = rand() % (xSpawnMax - xSpawnMin) + xSpawnMin;
		ySpawn = ySpawnMin;
	}
	
	//getting location for destination of asteroid
	int xDest = 30;
	int yDest = rand() % (yDestMax - yDestMin) + yDestMin;
	
	//getting trajectory of asteroid
	xTraj = xDest - xSpawn;
	yTraj = yDest - ySpawn;
	double totalTraj = sqrt(xTraj * xTraj + yTraj * yTraj);
	
	//initialize health and speed of asteroid
	health = 1;
	speed = 50;
	
	xTraj = speed * xTraj / totalTraj;
	yTraj = speed * yTraj / totalTraj;
	
	xLocation = xSpawn;
	yLocation = ySpawn;
	
	cout << "Asteroid created" << endl;
	cout << "xLocation: " << xLocation << endl;
	cout << "yLocation: " << yLocation << endl;
	cout << "xTraj: " << xTraj << endl;
	cout << "yTraj: " << yTraj << endl;
	cout << "health: " << health << endl;
	cout << "speed: " << speed << endl;
	
}

//Update Asteroid 
void Asteroid::update()
{
	xLocation = xLocation + xTraj;
	yLocation = yLocation + yTraj;
	
	cout << "Asteroid updated" << endl;
	cout << "xLocation: " << xLocation << endl;
	cout << "yLocation: " << yLocation << endl;
	
	//if asteroid has reached planet
	if (xLocation <= 30)
	{
		cout << "Asteroid crashed into planet" << endl;
		health = 0;
	}
}
	
	
	
	

	
	
	

