#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

#include "graphics.h"
#include "Ship.h"
#include "Planet.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Protect the Planet", sf::Style::Fullscreen | sf::Style::Close);
	
	//declare classes
	Ship* playerVals = new Ship();
	Planet* planetVals = new Planet();

	//declare variables
	double backgroundTime = time(NULL);

	//declare objects
	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	sf::Texture backgroundTexture;

	sf::RectangleShape player(sf::Vector2f(30.0, 60.0));
	sf::Texture playerTexture;

	sf::RectangleShape planet(sf::Vector2f(540.0, 540.0));
	sf::Texture planetTexture;

	//set textures before game loop
	loadBaseTextures(player, playerTexture, playerVals, planet, planetTexture, planetVals);

	//game loop
	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::TextEntered:
					if (evnt.text.unicode < 128) {
						printf("%c", evnt.text.unicode);
					}
			}
		}

		//movement functions
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
			playerVals->LeftRotation();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			playerVals->RightRotation();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			player.move(0.0, -1.5); //replace with ship move functions (note y-axis is inverted)
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			player.move(0.0, 1.5); //replace with ship move functions (note y-axis is inverted)
		}

		//update functions
		updatePlayer(player, playerTexture, playerVals);

		//drawing functions
		loadBackground(background, backgroundTexture, backgroundTime);
		drawGame(window, background, player, planet);
	}

	return 0;
}