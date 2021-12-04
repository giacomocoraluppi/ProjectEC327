#ifndef BULLET
#define BULLET
#include <cmath>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Ship.h"
#include <iostream>
using namespace std;

class Bullet
{
public:
    int speed;
    int damage;
    int xLocation;
    int yLocation;
    Bullet();
    Bullet(int, int);
    void update();
    void hitbox();
    int time;
    //Vecter2D trajectory();
    unsigned int getspeed() const;
    unsigned int getsdamage() const;
    unsigned int getlocation() const;
    
    
    
    
   
};


#endif //include guard

