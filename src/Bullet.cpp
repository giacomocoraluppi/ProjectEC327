#include "Bullet.h"

Bullet::Bullet(float xIn, float yIn, float angle)
{
	//initialize health and speed of bullet
    health = 1;
    speed = 5;
    
    //initialize location of bullet
	xLocation = xIn; 
	yLocation = yIn;
    
    //initialize trajectory of bullet
    xTraj = speed * cos(double(angle - 90)*3.14159/180.0);
    yTraj = speed * sin(double(angle - 90)*3.14159/180.0);

	//initialize graphics for the bullet
	sf::RectangleShape temp(sf::Vector2f(5, 20));
	sf::Texture tempTexture;

	tempTexture.loadFromFile("graphics/playerBeam.png");
	temp.setOrigin(2.5, 10);

	temp.setTexture(&bulletTexture);
	temp.setPosition(xLocation, yLocation);

	bulletSprite = temp;
	bulletTexture = tempTexture;
}

void Bullet::update()
{
        xLocation = xLocation + xTraj;
        yLocation = yLocation + xTraj;
        
        //cout << "Bullet updated" << endl;
        //cout << "xLocation: " << xLocation << endl;
        //cout << "yLocation: " << yLocation << endl;
}

void Bullet::loseLives()
{
    health--;
}
