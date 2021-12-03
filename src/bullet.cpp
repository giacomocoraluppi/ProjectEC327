#include "bullet.h"
bullet::bullet()
{
    speed=5;
    damage=1;
    location.x=0.0;
    location.y=0.0;
}
bullet::bullet(Point2D spaceship_headloation)
{
    speed=5;
    damage=1;
    location.x=spaceship_headloation.x;
    location.y=spaceship_headloation.y;
}

void bullet::update
{
        location.x += speed*time;
        location.y += speed*time;
        
        cout << "Bullet updated" << endl;
        cout << "xLocation: " << location.x << endl;
        cout << "yLocation: " << location.y << endl;
        
       
}
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

void hitbox()
{
    
}

Vector2D trajectory()
{
    
}


