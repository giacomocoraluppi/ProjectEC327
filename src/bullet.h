#ifndef bullet_H

#define bullet_H

#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

class bullet
{
public:
    unsigned int speed;
    unsigned int damage;
    int locationx;
    int locationy;
    bullet();
    bullet(int, int);
    void update();
    void hitbox();
    int time;
    //Vecter2D trajectory();
    unsigned int getspeed() const;
    unsigned int getsdamage() const;
    unsigned int getlocation() const;
    
    
    
    
    
};


#endif //include guard

