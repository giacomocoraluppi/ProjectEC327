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
	sf::Clock startBullet;
	sf::Time bulletSpawnRate = sf::milliseconds(300);

	sf::Clock startAsteroid;
	sf::Time AsteroidSpawnRate = sf::milliseconds(3000);

	sf::Clock difficultyTimer;
	sf::Time difficultyChangeRate = sf::milliseconds(15000);
	int currentDifficulty = 1;
	int difficultyMax = 10;

	double backgroundTime = time(NULL);
	double planetTime = time(NULL);

	//set counters before game
	int countAsteroid = 0;
	int countBullet = 0;

	double nowAsteroid = 0.0;
	double nowBullet = 0.0;

	//set animation speed
	sf::Time asteroidAnimationSpeed = sf::milliseconds(300);

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
	
		//generate bullet when key is pressed with a cooldown
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			if (startBullet.getElapsedTime() >= bulletSpawnRate)
			{
				startBullet.restart();
				bulletPtrArray[countBullet] = new Bullet(playerVals->xLocation, playerVals->yLocation, playerVals->angle);

				countBullet++;
			}
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
			if ((dist(asteroidPtrArray[i]->xLocation, asteroidPtrArray[i]->yLocation, playerVals->xLocation, playerVals->yLocation, 50) == true) && asteroidPtrArray[i]->hitFlag == false)
			{
				asteroidPtrArray[i]->hitFlag = true;
			
				asteroidPtrArray[i]->asteroidHit.restart();

				asteroidPtrArray[i]->loseLives();
				playerVals->loseLives(asteroidPtrArray[i]->damage);

				if (playerVals->health < 1)
				{
					cout << "Planet has been destroyed. You have lost the game!" << endl;
					//need to actually end game
				}
			}
		}

		//check to see if any asteroids crashed against the planet 
		for (int i = 0; i < countAsteroid; i++)
		{
			if ((dist(asteroidPtrArray[i]->xLocation, asteroidPtrArray[i]->yLocation, planetVals->xLocation, planetVals->yLocation, 250) == true) && asteroidPtrArray[i]->hitFlag == false)
			{
				asteroidPtrArray[i]->hitFlag = true;

				asteroidPtrArray[i]->asteroidHit.restart();

				/*
				asteroidPtrArray[i]->yTraj = 0; //asteroid stops moving
				asteroidPtrArray[i]->xTraj = 0; //asteroid stops moving
				asteroidPtrArray[i]->damage = 0; //asteroid no longer does damage
				*/

				asteroidPtrArray[i]->loseLives();
				planetVals->loseLives(asteroidPtrArray[i]->damage);
				
				if (planetVals->health < 1)
				{
					cout << "Planet has been destroyed. You have lost the game!" << endl;
					//need to end game here
				}
			}
		}

		//check to see if any asteroids have been hit by any bullets
		for (int i = 0; i < countAsteroid; i++)
		{
			for (int j = 0; j < countBullet; j++)
			{
				if ((dist(asteroidPtrArray[i]->xLocation, asteroidPtrArray[i]->yLocation, bulletPtrArray[j]->xLocation, bulletPtrArray[j]->yLocation, 50) == true) && asteroidPtrArray[i]->hitFlag == false)
				{
					asteroidPtrArray[i]->hitFlag = true;
					
					asteroidPtrArray[i]->asteroidHit.restart();

					asteroidPtrArray[i]->loseLives();
					bulletPtrArray[j]->loseLives();
				}

				if (bulletPtrArray[j]->health < 1)
				{
					delete bulletPtrArray[j];

					for (int k = j; k < countBullet; k++)
					{
						bulletPtrArray[k] = bulletPtrArray[k + 1];
					}
					countBullet--;
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

		//speeds up the game every 15 seconds
		if (currentDifficulty < difficultyMax) {
			if (difficultyTimer.getElapsedTime() >= difficultyChangeRate)
			{
				difficultyTimer.restart();
				AsteroidSpawnRate = AsteroidSpawnRate - sf::milliseconds(200);

				currentDifficulty++;
			}
		}

		//update functions for graphics
		updatePlayer(player, playerVals); 
		updatePlanet(planet, planetTexture, planetTime);

		for (int i = 0; i < countBullet; i++) {
			updateBullet(bulletPtrArray[i]);
		}

		for (int i = 0; i < countAsteroid; i++) {
			updateAsteroid(asteroidPtrArray[i]);

			if (asteroidPtrArray[i]->hitFlag == true)
			{
				asteroidCollision(asteroidPtrArray, countAsteroid, i, asteroidAnimationSpeed);
				asteroidPtrArray[i]->asteroidDestroyedAnimation(asteroidAnimationSpeed);
			}
		}

		//drawing functions
		loadBackground(background, backgroundTexture, backgroundTime);
		drawGame(window, background, player, planet, bulletPtrArray, countBullet, asteroidPtrArray, countAsteroid);
	}

	return 0;
}