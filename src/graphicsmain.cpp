#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

#include "graphics.h"
#include "Ship.h"
#include "Planet.h"
#include "Bullet.h"
#include "Asteroid.h"

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
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Protect the Planet", sf::Style::Fullscreen | sf::Style::Close);
	
	//declare classes
	Ship* playerVals = new Ship();
	Planet* planetVals = new Planet();
	
	
	Bullet* bulletPtrArray[500] = {};
	for (int i = 0; i < 500; i++)
	{
		bulletPtrArray[i] = new Bullet(0, 0, 90);
	}

	Asteroid* asteroidPtrArray[500] = {};
	for (int i = 0; i < 500; i++)
	{
		asteroidPtrArray[i] = new Asteroid();
	}

	//declare objects
	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	sf::Texture backgroundTexture;

	sf::RectangleShape player(sf::Vector2f(40.0, 70.0));
	sf::Texture playerTexture;

	sf::RectangleShape planet(sf::Vector2f(540.0, 540.0));
	sf::Texture planetTexture;

	//set textures before game loop
	loadBaseTextures(player, playerTexture, playerVals, planet, planetTexture, planetVals);

	//set timers before game
	//TEST CODE
	sf::Clock startBullet;
	sf::Time bulletSpawnRate = sf::milliseconds(1000);

	sf::Clock startAsteroid;
	sf::Time AsteroidSpawnRate = sf::milliseconds(3000);

	//double startAsteroid = time(NULL);
	double backgroundTime = time(NULL);
	double planetTime = time(NULL);

	//set counters before game
	int countAsteroid = 0;
	int countBullet = 0;

	double nowAsteroid = 0.0;
	double nowBullet = 0.0;

	//game loop
	while (window.isOpen()) {

		//window events
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
				case sf::Event::Closed:
					window.close();
					break;
			}
		}

		//movement functions
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
			playerVals->RightRotation();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			playerVals->LeftRotation();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			playerVals->WPressed(); //replace with ship move functions (note y-axis is inverted)
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			playerVals->SPressed(); //replace with ship move functions (note y-axis is inverted)
		}
	
		//randomly generate bullets
		if (startBullet.getElapsedTime() >= bulletSpawnRate)
		{
			startBullet.restart();
			bulletPtrArray[countBullet] = new Bullet(playerVals->xLocation, playerVals->yLocation, playerVals->angle);

			countBullet++;
		}

		//randmly generate asteroids
		if (startAsteroid.getElapsedTime() >= AsteroidSpawnRate)
		{
			startAsteroid.restart();
			asteroidPtrArray[countAsteroid] = new Asteroid();

			countAsteroid++;
		}

		//check to see if any asteroids crashed against the ship
		for (int i=0; i<countAsteroid; i++)
		{
			if (dist(asteroidPtrArray[i]->xLocation, asteroidPtrArray[i]->yLocation, playerVals->xLocation, playerVals->yLocation, 50) == true)
			{
				asteroidPtrArray[i]->loseLives();
				playerVals->loseLives();
				if (asteroidPtrArray[i]->health < 1)
				{
					for (int k=i; k < countAsteroid; k++)
					{
						asteroidPtrArray[k] = asteroidPtrArray[k+1];
					}
					countAsteroid--;
				}
				if (playerVals->health < 1)
				{
					cout << "Ship has been destroyed. You have lost the game!" << endl;
					//need to actually end game
				}
			}
		}

		//check to see if any asteroids have been hit by any bullets
		for (int i = 0; i < countAsteroid; i++)
		{
			for (int j = 0; j < countBullet; j++)
			{
				if (dist(asteroidPtrArray[i]->xLocation, asteroidPtrArray[i]->yLocation, bulletPtrArray[j]->xLocation, bulletPtrArray[j]->yLocation, 50) == true)
				{
					asteroidPtrArray[i]->loseLives();
					bulletPtrArray[j]->loseLives();
					if (asteroidPtrArray[i]->health < 1)
					{
						for (int k = i; k < countAsteroid; k++)
						{
							asteroidPtrArray[k] = asteroidPtrArray[k + 1];
						}
						countAsteroid--;
					}
					if (bulletPtrArray[j]->health < 1)
					{
						for (int k = j; k < countBullet; k++)
						{
							bulletPtrArray[k] = bulletPtrArray[k + 1];
						}
						countBullet--;
					}
				}
			}
		}

		//delete bullet if out of screen
		for (int i = 0; i < countBullet; i++)
		{
			if (bulletPtrArray[i]->IsOut() == true)
			{
				for (int k = i; k < countBullet; k++)
				{
					bulletPtrArray[k] = bulletPtrArray[k + 1];
				}
				countBullet--;
			}
		}

		//update functions for graphics
		updatePlayer(player, playerVals); 
		updatePlanet(planet, planetTexture, planetTime);

		for (int i = 0; i < countBullet; i++) {
			updateBulllet(bulletPtrArray[i]);
		}

		for (int i = 0; i < countAsteroid; i++) {
			updateAsteroid(asteroidPtrArray[i]);
		}

		//drawing functions
		loadBackground(background, backgroundTexture, backgroundTime);
		drawGame(window, background, player, planet, bulletPtrArray, countBullet, asteroidPtrArray, countAsteroid);
	}

	return 0;
}
