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
    int health;
    int speed;
    int xLocation;
    int yLocation;
    int xTraj;
    int yTraj;
    
    Bullet(int, int, int);
    void update(); 
    void loseLives();
};

#endif
