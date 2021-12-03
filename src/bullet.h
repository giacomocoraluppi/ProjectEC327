#ifndef bullet_H

#define bullet_H

#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Point2D.h"
using namespace std;

class bullet
{
private:
    unsigned int speed;
    unsigned int damage;
    Point2D location;
public:
    bullet();
    bullet(Point2D spaceship_loation);
    void update();
    void hitbox();
    int time;
    Vecter2D trajectory();
    unsigned int getspeed() const;
    unsigned int getsdamage() const;
    unsigned int getlocation() const;
    
    
    
    
    
};


#endif //include guard

