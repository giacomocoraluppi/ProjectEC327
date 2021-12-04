#include "Asteroid.h"
#include "Ship.h"
#include "Planet.h"
#include "Bullet.h"
#include <iostream>
using namespace std;

int main()
{
	Planet* thePlanet = new Planet();
	Ship* theShip = new Ship();
	
	//these will need to be in loop
	Bullet* bullet1 = new Bullet(theShip->xLocation, theShip->yLocation, theShip->leftRotation, theShip->rightRotation);
	Asteroid* asteroid1 = new Asteroid();
	
	/*
	cout << "xLocation: " << asteroid1->xLocation << endl;
	cout << "yLocation: " << asteroid1->yLocation << endl;
	cout << "xTraj: " << asteroid1->xTraj << endl;
	cout << "yTraj: " << asteroid1->yTraj << endl;
	cout << "health: " << asteroid1->health << endl;
	cout << "speed: " << asteroid1->speed << endl;
	*/
	
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	
	if (asteroid1 -> health == 0)
	{
		cout << "crashed********" << endl;
		delete asteroid1;
	}
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	

	return 0;
}
