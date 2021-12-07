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

	int size = 100;

	//intialize random seed
	srand(time(NULL));
	
	int random = rand() % 4;
	
	int xSpawn;
	int ySpawn;

	sf::RectangleShape tempSprite(sf::Vector2f(size, size));
	sf::Texture tempTexture;

	asteroidTexture = tempTexture;

	asteroidTexture.loadFromFile("graphics/asteroid2.png");
	tempSprite.setTexture(&asteroidTexture);
	tempSprite.setOrigin(size / 2, size / 2);

	asteroidSprite = tempSprite;

	//choose texture randomly
	//getting location where asteroid is spawning from
	if (random == 0 || random == 1)
	{
		//asteroid comes from right side of screen
		xSpawn = xSpawnMax;
		ySpawn = rand() % (ySpawnMax - ySpawnMin) + ySpawnMin;
		rotation = -.5;
		angle = 90;
	}
	else if (random == 2)
	{
		//asteroid comes from top side of screen
		xSpawn = rand() % (xSpawnMax - xSpawnMin) + xSpawnMin;
		ySpawn = ySpawnMax;
		rotation = .08;
		angle = 0;
	}
	else if (random == 3)
	{
		//asteroid comes from bottom side of screen
		xSpawn = rand() % (xSpawnMax - xSpawnMin) + xSpawnMin;
		ySpawn = ySpawnMin;
		rotation = 1;
		angle = 35;
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
	speed = 3;
	
	xTraj = speed * xTraj / totalTraj;
	yTraj = speed * yTraj / totalTraj;
	
	xLocation = xSpawn;
	yLocation = ySpawn;

	asteroidSprite.setPosition(xLocation, yLocation);
	
	/*
	cout << "Asteroid created" << endl;
	cout << "xLocation: " << xLocation << endl;
	cout << "yLocation: " << yLocation << endl;
	cout << "xTraj: " << xTraj << endl;
	cout << "yTraj: " << yTraj << endl;
	cout << "health: " << health << endl;
	cout << "speed: " << speed << endl;
	*/
	
}

//Update Asteroid 
void Asteroid::update()
{
	xLocation = xLocation + xTraj;
	yLocation = yLocation + yTraj;
	angle = angle + rotation;
	
	/*
	cout << "Asteroid updated" << endl;
	cout << "xLocation: " << xLocation << endl;
	cout << "yLocation: " << yLocation << endl;
	*/
}

void Asteroid::loseLives()
{
    health--;
}
