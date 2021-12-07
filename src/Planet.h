#ifndef PLANET
#define PLANET
#include <iostream>

#include <SFML/Graphics.hpp>
#include <Time.h>

using namespace std;

class Planet
{
public:
    int health;
    float xLocation;
    float yLocation;

	bool hit;
	sf::Clock planetHit;

    Planet();
    void loseLives(int damage);
	void planetShake();
};
#endif
