#include "Asteroid.h"
#include <iostream>
using namespace std;

int main()
{
	//Asteroid();
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
