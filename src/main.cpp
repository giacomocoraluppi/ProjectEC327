#include "Asteroid.h"
#include "Ship.h"
#include "Planet.h"
#include "Bullet.h"

#include <chrono>
#include <string>
#include <cmath>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace std;

bool dist(int x1, int y1, int x2, int y2, int max)
{
	if (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) < max)
	{
		return true;
	}
	else 
	{	
		return false;
	}
}

int main()
{
	//initialize thePlanet and theShip
	Planet* thePlanet = new Planet();
	Ship* theShip = new Ship();
	Bullet* bullet[100] = {};
	for (int i=0; i<100; i++)
	{
		bullet[i] = new Bullet(0,0,0);
	}
	Asteroid* asteroid[100] = {};
	for (int i=0; i<100; i++) 
	{
		asteroid[i] = new Asteroid();
	}
	
	std::chrono::steady_clock::time_point startAsteroid = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point startBullet = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point nowAsteroid = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point nowBullet = std::chrono::steady_clock::now();
	int countAsteroid = 0;
	int countBullet = 0;
	
	std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now();
	int respawnTime = 1000;
	
	while (true)
	{
		nowAsteroid = std::chrono::steady_clock::now();
		nowBullet = std::chrono::steady_clock::now();
		nowTime = std::chrono::steady_clock::now();
		
		//every 15 seconds decrease respawn time by 200 milliseconds
		if (std::chrono::duration_cast<std::chrono::milliseconds> (nowTime-startTime).count() >= 5000)
		{
			startTime = std::chrono::steady_clock::now();
			respawnTime = respawnTime - 50;
			cout << "respawn time in milliseconds: " << respawnTime << endl;
		}
		
		//every 3*respawnTime milliseconds spawn a new asteroid
		if (std::chrono::duration_cast<std::chrono::milliseconds> (nowAsteroid-startAsteroid).count() >= 3*respawnTime)
		{
			startAsteroid = std::chrono::steady_clock::now();
			asteroid[countAsteroid] = new Asteroid();
			countAsteroid++;
			cout << "new asteroid" << endl;
		}
		
		//every 1*respawnTime milliseconds shoot a new bullet
		if (std::chrono::duration_cast<std::chrono::milliseconds> (nowBullet-startBullet).count() >= 1*respawnTime)
		{
			startBullet = std::chrono::steady_clock::now();
			bullet[countBullet] = new Bullet(theShip->xLocation, theShip->yLocation, theShip->angle);
			countBullet++;
			cout << "new bullet" << endl;
		}
		
		//update rotation and location of ship
		//if (key = <)
		{
			theShip->LeftRotation();
		}
		//if (key =>)
		{
			theShip->RightRotation();
		}
		theShip->update();
		
		//update location of each bullet
		for (int i=0; i<countBullet; i++)
		{
			bullet[i]->update();
		}
		
		//update location of each asteroid
		for (int i=0; i<countAsteroid; i++)
		{
			asteroid[i]->update();
		}
		
		//check to see if any asteroids crashed against the planet 
		for (int i=0; i<countAsteroid; i++)
		{
			if (dist(asteroid[i]->xLocation,asteroid[i]->yLocation,thePlanet->xLocation,thePlanet->yLocation,10) == true)
			{
				asteroid[i]->loseLives();
				thePlanet->loseLives();
				if (asteroid[i]->health < 1)
				{
					delete asteroid[i];
				}
				if (thePlanet->health < 1)
				{
					cout << "Planet has been destroyed. You have lost the game!" << endl;
					exit;
				}
			}
		}
		
		//check to see if any asteroids crashed against the ship
		for (int i=0; i<countAsteroid; i++)
		{
			if (dist(asteroid[i]->xLocation,asteroid[i]->yLocation,theShip->xLocation,theShip->yLocation,10) == true)
			{
				asteroid[i]->loseLives();
				theShip->loseLives();
				if (asteroid[i]->health < 1)
				{
					delete asteroid[i];
				}
				if (theShip->health < 1)
				{
					cout << "Ship has been destroyed. You have lost the game!" << endl;
					exit;
				}
			}
		}
		
		//check to see if any asteroids have been hit by any bullets
		for (int i=0; i<countAsteroid; i++)
		{
			for (int j=0; j<countBullet; j++)
			{
				if (dist(asteroid[i]->xLocation,asteroid[i]->yLocation,bullet[j]->xLocation,bullet[j]->yLocation,10) == true)
				{
					asteroid[i]->loseLives();
					bullet[j]->loseLives();
					if (asteroid[i]->health < 1)
					{
						delete asteroid[i];
					}
					if (bullet[j]->health < 1)
					{
						delete bullet[j];
					}
				}
			}
		}
	}
	
	return 0;
}
