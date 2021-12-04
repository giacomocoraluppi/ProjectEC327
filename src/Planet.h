#ifndef PLANET
#define PLANET
#include <iostream>
using namespace std;

class Planet
{
public:
    int health;
    int xLocation;
    int yLocation;

    Planet();
    int loseLives();
};

#endif
