#include "Bullet.h"

Bullet::Bullet(float xIn, float yIn, float angle)
{
	//initialize health and speed of bullet
    health = 1;
    speed = 5;
    
    //initialize location of bullet
	xLocation = xIn + 20 * cos(double(angle - 90)*3.14159 / 180.0);
	yLocation = yIn + 20 * sin(double(angle - 90)*3.14159 / 180.0);
    
    //initialize trajectory of bullet
	xTraj = (xLocation - xIn);
	yTraj = (yLocation - yIn);

	double totalTraj = sqrt(xTraj * xTraj + yTraj * yTraj);
	
	xTraj = speed * cos(double(angle - 90)*3.14159 / 180.0);
	yTraj = speed * sin(double(angle - 90)*3.14159 / 180.0);
	

	//initialize graphics for the bullet
	sf::RectangleShape temp(sf::Vector2f(5, 20));
	sf::Texture tempTexture;

	tempTexture.loadFromFile("graphics/playerBeam.png");
	temp.setOrigin(2.5, 0);

	temp.setTexture(&bulletTexture);
	temp.setPosition(xLocation, yLocation);
	temp.setRotation(angle);

	bulletSprite = temp;
	bulletTexture = tempTexture;
}

void Bullet::update()
{
        xLocation = xLocation + xTraj;
        yLocation = yLocation + yTraj;
        
        //cout << "Bullet updated" << endl;
        //cout << "xLocation: " << xLocation << endl;
        //cout << "yLocation: " << yLocation << endl;
}

void Bullet::loseLives()
{
    health--;
}

/*
bool Bullet::IsOut()
{
//RESOLUTION_X and RESOLUTION_Y represents the edge of the window
	// Returns true if the projectile is out of the screen area so we can remove it
	if (xLocaiton < -10 || xLocation > RESOLUTION_X + 10 || yLocation < -10 || yLocation > RESOLUTION_Y + 10)
	{
		return true;
	}
	return false;
}
*/