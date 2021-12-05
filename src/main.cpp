#include "Asteroid.h"
#include "Ship.h"
#include "Planet.h"
#include "Bullet.h"
#include <string>
#include <sstream>
#include <unistd.h>
#include <ctime>
#include <iostream>
using namespace std;

void Update()
{
	
	//are colliding

}



int main()
{
	//initialize thePlanet and theShip
	Planet* thePlanet = new Planet();
	Ship* theShip = new Ship();
	
	int start = time(NULL);
	int now = 0;
	int count = 0;
	while (true)
	{
		now = time(NULL) - start;
		if (now > 2)
		{
			start = time(NULL);
		  	stringstream ss;  
			ss<<count;  
		    string s;  
   		    ss>>s;  
   		    
			//string bulletName = "bullet" + s;
			//cout << bulletName << endl;
			Bullet* ("bullet" + s) = new Bullet(theShip->xLocation, theShip->yLocation, theShip->angle);
			//Asteroid* asteroid1 = new Asteroid();
			count++;
		}

		
	}

	/*
	if (asteroid1 -> health == 0)
	{
		cout << "crashed********" << endl;
		delete asteroid1;
	}
	
	asteroid1->update();
	asteroid1->update();
	asteroid1->update();
	*/

	return 0;
}
