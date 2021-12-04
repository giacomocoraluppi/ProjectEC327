#include "Bullet.h"
#include <iostream>
using namespace std; 

Bullet::Bullet(int xIn, int yIn, int angle)
{
	//initialize damage and speed of bullet
    damage=1;
    speed=5;
    
    //initialize location of bullet
    xLocation=xIn;
    yLocation=yIn;
    
    //initialize trajectory of bullet
    xTraj = cos(double(angle*3.14159/180.0));
    yTraj = sin(double(angle*3.14159/180.0));
    xTraj = speed * xTraj;
    yTraj = speed * yTraj;
}

void Bullet::update()
{
        xLocation = xLocation + xTraj;
        yLocation = yLocation + xTraj;
        
        cout << "Bullet updated" << endl;
        cout << "xLocation: " << xLocation << endl;
        cout << "yLocation: " << yLocation << endl;
}
