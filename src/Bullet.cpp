#include "Bullet.h"
#include <iostream>
using namespace std; 

Bullet::Bullet(int xIn, int yIn, int leftRot, int rightRot)
{
	//initialize damage and speed of bullet
    damage=1;
    speed=5;
    
    //initialize location of bullet
    xLocation=xIn;
    yLocation=yIn;
}
/*
bullet::bullet(spaceship_headloationx,spaceship_headlocationy)
{
    speed=5;
    damage=1;
    locationx=spaceship_headloation.x;
    locationy=spaceship_headloation.y;
}
*/
void Bullet::update()
{
        xLocation += speed*time;
        yLocation += speed*time;
        
        cout << "Bullet updated" << endl;
        cout << "xLocation: " << xLocation << endl;
        cout << "yLocation: " << yLocation << endl;
        
       
}
/*
unsigned int bullet::getspeed() const
{
    return speed;
}

unsigned int damage bullet::getdamage() const
{
    return damage;
}

Point2D bullet::getlocation() const
{
    return location;
}

Vector2D trajectory()
{
    
}
*/

