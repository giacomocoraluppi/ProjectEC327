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

void Bullet::update()
{
        xLocation = xLocation + xTraj;
        yLocation = yLocation + xTraj;
        
        cout << "Bullet updated" << endl;
        cout << "xLocation: " << xLocation << endl;
        cout << "yLocation: " << yLocation << endl;
}

int Bullet::loseLives()
{
    health--;
    return health;
}
