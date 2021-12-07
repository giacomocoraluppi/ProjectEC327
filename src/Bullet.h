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

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Bullet
{
public:
    int health;
    int speed;
	float rotation;

    float xLocation;
    float yLocation;
    float xTraj;
    float yTraj;
	sf::RectangleShape bulletSprite;
	sf::Texture bulletTexture;
    
    Bullet(float, float, float);
    void update(); 
    void loseLives();
    bool IsOut();
};

#endif
