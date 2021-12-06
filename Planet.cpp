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
}

void Planet::loseLives()
{
    health--;
}
