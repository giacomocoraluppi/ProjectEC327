#include "Planet.h"
#include <iostream>
using namespace std;

Planet::Planet()
{
	//initialize health of planet
    health = 10;
    
    //initialize location of planet
    xLocation = 0;
    yLocation = 540;

	hit = false;
}

void Planet::loseLives(int damage)
{
	health = health - damage;

	hit = true;
	planetHit.restart();
}

void Planet::planetShake() {
	
	if ((planetHit.getElapsedTime().asMilliseconds() < 200) && hit == true) { //first phase frame
		xLocation = xLocation + 1;
	}

	else if ((planetHit.getElapsedTime().asMilliseconds() < 400) && hit == true) { //second phase
		xLocation = xLocation -1;
	}
	else { //set back to normal
		xLocation = 0;
		yLocation = 540;

		hit = false;
	}

	return;
}
