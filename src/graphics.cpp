#include "graphics.h"

void loadBackground(RectangleShape &background, Texture &backgroundTexture, double &gameTime) {
	double currentTime = time(NULL);
	int timeLoop = currentTime - gameTime;

	switch(timeLoop){
		case 0:
			backgroundTexture.loadFromFile("graphics/backgroundframe1.png");
			break;
		case 1:
			backgroundTexture.loadFromFile("graphics/backgroundframe2.png");
			break;
		case 2:
			backgroundTexture.loadFromFile("graphics/backgroundframe3.png");
			break;
		case 3:
			backgroundTexture.loadFromFile("graphics/backgroundframe4.png");
			break;
		case 4:
			backgroundTexture.loadFromFile("graphics/backgroundframe5.png");
			break;
		case 5:
			backgroundTexture.loadFromFile("graphics/backgroundframe6.png");
			break;
		case 6:
			backgroundTexture.loadFromFile("graphics/backgroundframe7.png");
			gameTime = time(NULL); ///reset time for loop
			break;
		}
	background.setTexture(&backgroundTexture);
	return;
}


void loadBaseTextures(RectangleShape &player, Texture &playerTexture, Ship *ship, RectangleShape &planet, Texture &planetTexture, Planet * planetVals){

	//load player sprite
	playerTexture.loadFromFile("graphics/shipDefault.png"); //might need .. because main is in src folder in main code
	player.setTexture(&playerTexture);

	player.setOrigin(15.0, 30.0); 
	player.setRotation(ship->angle); //change to get picture from the player object
	player.setPosition(ship->xLocation, ship->yLocation); //change to get picture from the player object

	//load planet sprite
	planetTexture.loadFromFile("graphics/planetframe1.png");
	planet.setTexture(&planetTexture);

	planet.setOrigin(220.0, 220.0);
	planet.setPosition(planetVals->xLocation, planetVals->yLocation);
}

void drawGame(RenderWindow &window, RectangleShape &background, RectangleShape &player, RectangleShape &planet, Bullet * bulletPtrArray[], int countBullet, Asteroid * asteroidPtrArray[], int countAsteroid, Lives * livesPtrArray[], int lifeCount, RectangleShape &tens, RectangleShape &ones) {
	window.clear(); //clear buffer

	window.draw(background); //background must be drawn first'

	window.draw(planet);

	for (int i = 0; i < countBullet; i++) {
		window.draw(bulletPtrArray[i]->bulletSprite);
	}

	window.draw(player);

	for (int i = 0; i < countAsteroid; i++) {
		window.draw(asteroidPtrArray[i]->asteroidSprite);
	}

	for (int i = 0; i < lifeCount; i++) {
		window.draw(livesPtrArray[i]->livesSprite);
	}

	window.draw(tens);
	window.draw(ones);

	window.display(); //display drawn objects
}

void updatePlayer(RectangleShape &player, Ship *ship){ //run during main to update appropiate textures
	player.setRotation(ship->angle); //change to get picture from the player object
	player.setPosition(ship->xLocation, ship->yLocation); //change to get picture from the player object
	return;
}

void updatePlanet(RectangleShape &planet, Texture &planetTexture, Planet * planetVals, double &gameTime) { //run during main to update appropiate textures
	double currentTime = time(NULL);
	int timeLoop = currentTime - gameTime;

	switch (timeLoop) {
	case 0:
		planetTexture.loadFromFile("graphics/planetframe1.png");
		break;
	case 1:
		planetTexture.loadFromFile("graphics/planetframe2.png");
		break;
	case 2:
		planetTexture.loadFromFile("graphics/planetframe3.png");
		break;
	case 3:
		planetTexture.loadFromFile("graphics/planetframe4.png");
		break;
	case 4:
		planetTexture.loadFromFile("graphics/planetframe5.png");
		break;
	case 5:
		planetTexture.loadFromFile("graphics/planetframe6.png");
		break;
	case 6:
		planetTexture.loadFromFile("graphics/planetframe7.png");
		break;
	case 7:
		planetTexture.loadFromFile("graphics/planetframe8.png");
		break;
	case 8:
		planetTexture.loadFromFile("graphics/planetframe9.png");
		break;
	case 9:
		planetTexture.loadFromFile("graphics/planetframe10.png");
		break;
	case 10:
		planetTexture.loadFromFile("graphics/planetframe11.png");
		break;
	case 11:
		planetTexture.loadFromFile("graphics/planetframe12.png");
		gameTime = time(NULL); ///reset time for loop
		break;
	}

	planet.setTexture(&planetTexture);
	planet.setPosition(planetVals->xLocation , planetVals->yLocation);

	return;
}

void updateBullet(Bullet * bullet) { //run during main to update bullet locations
	bullet->update();
	bullet->bulletSprite.setPosition(bullet->xLocation, bullet->yLocation);
	return;
}

void updateAsteroid(Asteroid * asteroid) { //run during main to update asteroid locations
	asteroid->update();
	asteroid->asteroidSprite.setPosition(asteroid->xLocation, asteroid->yLocation);
	asteroid->asteroidSprite.setRotation(asteroid->angle);
	return;
}

void updatePlanetLives(RectangleShape &tensSprite, RectangleShape &onesSprite, Texture &tens, Texture &ones, int lives) {
	int livesTens = lives/10;
	int livesOnes = (lives - (livesTens*10));

	switch (livesTens) {
		case 0:
			tens.loadFromFile("graphics/digit0.png");
			break;
		case 1:
			tens.loadFromFile("graphics/digit1.png");
			break;
		case 2:
			tens.loadFromFile("graphics/digit2.png");
			break;
		case 3:
			tens.loadFromFile("graphics/digit3.png");
			break;
		case 4:
			tens.loadFromFile("graphics/digit4.png");
			break;
		case 5:
			tens.loadFromFile("graphics/digit5.png");
			break;
		case 6:
			tens.loadFromFile("graphics/digit6.png");
			break;
		case 7:
			tens.loadFromFile("graphics/digit7.png");
			break;
		case 8:
			tens.loadFromFile("graphics/digit8.png");
			break;
		case 9:
			tens.loadFromFile("graphics/digit9.png");
			break;
	}

	switch (livesOnes) {
		case 0:
			ones.loadFromFile("graphics/digit0.png");
			break;
		case 1:
			ones.loadFromFile("graphics/digit1.png");
			break;
		case 2:
			ones.loadFromFile("graphics/digit2.png");
			break;
		case 3:
			ones.loadFromFile("graphics/digit3.png");
			break;
		case 4:
			ones.loadFromFile("graphics/digit4.png");
			break;
		case 5:
			ones.loadFromFile("graphics/digit5.png");
			break;
		case 6:
			ones.loadFromFile("graphics/digit6.png");
			break;
		case 7:
			ones.loadFromFile("graphics/digit7.png");
			break;
		case 8:
			ones.loadFromFile("graphics/digit8.png");
			break;
		case 9:
			ones.loadFromFile("graphics/digit9.png");
			break;
	}

	tensSprite.setTexture(&tens);
	onesSprite.setTexture(&ones);
}

void setLives(Lives * life, int lifeNum) {
		life->xLocation = life->xLocation - (life->size * lifeNum + 20);
		life->livesSprite.setPosition(life->xLocation, life->yLocation);
}

void asteroidCollision(Asteroid * asteroidPtrArray[], int &countAsteroid, int currentAsteroid, Time animationSpeed) {
	asteroidPtrArray[currentAsteroid]->yTraj = 0; //asteroid stops moving
	asteroidPtrArray[currentAsteroid]->xTraj = 0; //asteroid stops moving
	asteroidPtrArray[currentAsteroid]->damage = 0; //asteroid no longer does damage

	if (asteroidPtrArray[currentAsteroid]->asteroidHit.getElapsedTime() > animationSpeed) {

		delete asteroidPtrArray[currentAsteroid]; //free up memory of current asteroid

		for (int k = currentAsteroid; k < countAsteroid; k++)
		{
			asteroidPtrArray[k] = asteroidPtrArray[k + 1]; //shift all pointers
		}
		countAsteroid--;

	}
}