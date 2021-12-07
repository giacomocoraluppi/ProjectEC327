#ifndef ASTEROID
#define ASTEROID

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <time.h>

#include <SFML/Graphics.hpp>

using namespace std;

class Asteroid
{
public:
	int health;
	int speed;
	int size;
	int damage;

	float angle;
	float rotation;

	float xLocation;
	float yLocation;
	double xTraj;
	double yTraj;

	sf::RectangleShape asteroidSprite;
	sf::Texture asteroidTexture;
	sf::Clock asteroidHit;

	Asteroid();
	void update();
	void loseLives();

	void asteroidDestroyedAnimation(sf::Time animationSpeed);
};
	
#endif
