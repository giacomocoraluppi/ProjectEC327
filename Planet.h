#ifndef PLANET
#define PLANET
#include <iostream>
using namespace std;

class Planet
{
public:
    int health;
    float xLocation;
    float yLocation;

    Planet();
    void loseLives();
};

#endif
