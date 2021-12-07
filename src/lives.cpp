#include "Lives.h"

Lives::Lives() {
	size = 80;
	xLocation = 1920 - (size/2 + 20); //subtracted 40 from each edge
	yLocation = 1080 - (size/2 + 20);

	sf::RectangleShape tempSprite(sf::Vector2f(size, size));
	sf::Texture tempTexture;

	//initialize textures
	tempTexture.loadFromFile("graphics/hearts.png");
	livesTexture = tempTexture;

	tempSprite.setTexture(&livesTexture);
	livesSprite = tempSprite;

	livesSprite.setOrigin(size / 2, size / 2);
}
