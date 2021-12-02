#include <iostream>
#include "Planet.h"

using namespace std;

Planet::Planet()
{
    health = 10;
    
    location_x = 0;
    location_y = 540;
}

void Planet::loseLives()
{
    health--;
}

/*bool Planet::update()
{
    
}
*/
