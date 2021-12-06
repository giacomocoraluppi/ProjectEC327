#include "Bullet.h"
#include <iostream>
using namespace std; 

Bullet::Bullet(int xIn, int yIn, int angle)
{
	//initialize health and speed of bullet
    health=1;
    speed=5;
    
    //initialize location of bullet
    xLocation=xIn;
    yLocation=yIn;
    
    //initialize trajectory of bullet
    xTraj = speed * cos(double(angle)*3.14159/180.0);
    yTraj = speed * sin(double(angle)*3.14159/180.0);
}

/*
Bullet::~Bullet()
{
}

*/

void Bullet::update()//should includes a time elapsedTime
{
	/*
	xLocation += elapsedTime * xTraj;
	yLocation += elapsedTime * yTraj;
	*/
        xLocation = xLocation + xTraj;
        yLocation = yLocation + xTraj;
        
        //cout << "Bullet updated" << endl;
        //cout << "xLocation: " << xLocation << endl;
        //cout << "yLocation: " << yLocation << endl;
}

/*
bool Bullet::IsOut()
{
//RESOLUTION_X and RESOLUTION_Y represents the edge of the window
	// Returns true if the projectile is out of the screen area so we can remove it
	if (xLocaiton < -10 || xLocation > RESOLUTION_X + 10 || yLocation < -10 || yLocation > RESOLUTION_Y + 10)
	{
		return true;
	}
	return false;
}
*/

void Bullet::loseLives()
{
    health--;
}
