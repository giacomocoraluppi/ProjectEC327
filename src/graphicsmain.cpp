#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

#include "graphics.h"
#include "Ship.h"
#include "Planet.h"
#include "Bullet.h"
#include "Asteroid.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Protect the Planet", sf::Style::Fullscreen | sf::Style::Close);
	
	//declare classes
	Ship* playerVals = new Ship();
	Planet* planetVals = new Planet();
	
	
	Bullet* bulletPtrArray[100] = {};
	for (int i = 0; i < 100; i++)
	{
		bulletPtrArray[i] = new Bullet(0, 0, 90);
	}

	Asteroid* asteroidPtrArray[100] = {};
	for (int i = 0; i < 100; i++)
	{
		asteroidPtrArray[i] = new Asteroid();
	}

	// /*TEST CODE
	sf::RectangleShape bulletTest(sf::Vector2f(5, 20));
	sf::Texture bulletTexture;

	bulletTexture.loadFromFile("graphics/playerBeam.png");
	bulletTest.setTexture(&bulletTexture);

	bulletTest.setPosition(540, 700);
	// */

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
	double startAsteroid = time(NULL);
	double startBullet = time(NULL);
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
		nowBullet = time(NULL) - startBullet;

		if (nowBullet >= 1)
		{
			startBullet = time(NULL);
			bulletPtrArray[countBullet] = new Bullet(playerVals->xLocation, playerVals->yLocation, playerVals->angle);

			//test output
			cout << "New bullet " << countBullet << " generated at (" << bulletPtrArray[countBullet]->xLocation << ", " << bulletPtrArray[countBullet]->yLocation << ")." << endl;
			
			countBullet++;
		}


		//randmly generate asteroids
		nowAsteroid = time(NULL) - startAsteroid;

		if (nowAsteroid >= 3)
		{
			startAsteroid = time(NULL);
			asteroidPtrArray[countAsteroid] = new Asteroid();
			countAsteroid++;
		}

		//update functions for graphics
		updatePlayer(player, playerVals); 
		updatePlanet(planet, planetTexture, planetTime);

		for (int i = 0; i < countBullet; i++) {
			updateBulllet(bulletPtrArray[i]);
		}

		//drawing functions
		loadBackground(background, backgroundTexture, backgroundTime);

		drawGame(window, background, player, planet, bulletPtrArray, countBullet, asteroidPtrArray, countAsteroid);
	}

	return 0;
}