#ifndef PLANET
#define PLANET

#include <iostream>

using namespace std;

class Planet
{
public:
    double health;
    int location_x;
    int location_y;

    Planet();

    void loseLives();
   // void update();
};

#endif
