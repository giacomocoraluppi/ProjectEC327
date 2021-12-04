#include "bullet.h"
bullet::bullet()
{
    speed=5;
    damage=1;
    locationx=0;
    locationy=0;
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
void bullet::update()
{
        locationx += speed*time;
        locationy += speed*time;
        
        cout << "Bullet updated" << endl;
        cout << "xLocation: " << locationx << endl;
        cout << "yLocation: " << locationy << endl;
        
       
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

