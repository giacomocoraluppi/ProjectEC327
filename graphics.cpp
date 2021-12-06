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

void drawGame(RenderWindow &window, RectangleShape &background, RectangleShape &player, RectangleShape &planet) {
	window.clear(); //clear buffer

	window.draw(background);
	window.draw(player);
	window.draw(planet);

	window.display(); //display drawn objects
}

void updatePlayer(RectangleShape &player, Ship *ship){ //run during main to update appropiate textures
	player.setRotation(ship->angle); //change to get picture from the player object
	player.setPosition(ship->xLocation, ship->yLocation); //change to get picture from the player object
	return;
}

void updatePlanet(RectangleShape &planet, Texture &planetTexture, double &gameTime) { //run during main to update appropiate textures
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
	return;
}

void updateAsteroid() { //run during main to update appropiate textures
	return;
}