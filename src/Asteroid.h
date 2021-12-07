#ifndef ASTEROID
#define ASTEROID

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace std;

class Asteroid
{
public:
	int health;
	int speed;
	int size;
	float angle;
	float rotation;

	float xLocation;
	float yLocation;
	double xTraj;
	double yTraj;
	sf::RectangleShape asteroidSprite;
	sf::Texture asteroidTexture;

	Asteroid();
	void update();
	void loseLives();
};
	
#endif
