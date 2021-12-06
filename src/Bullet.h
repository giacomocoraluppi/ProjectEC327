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
    float xLocation;
    float yLocation;
    float xTraj;
    float yTraj;
    
    Bullet(int, int, int);
    void update(); 
    void loseLives();
};

#endif
