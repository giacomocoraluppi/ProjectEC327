#ifndef GRAPHICS_H //include guard
#define GRAPHICS_H //include guard

#include <SFML/Graphics.hpp>
#include <time.h>

#include "Ship.h"
#include "Planet.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "lives.h"

using namespace sf;

//sets the background depending on system time
void loadBackground(RectangleShape &background, Texture &backgroundTexture, double &time);

//sets the initial tectures and positions for all perminant objects
void loadBaseTextures(RectangleShape &player, Texture &playerTexture, Ship *ship, RectangleShape &planet, Texture &planetTexture, Planet * planetVals);

//draws the screen each frame
void drawGame(RenderWindow &window, RectangleShape &background, RectangleShape &player, RectangleShape &planet, Bullet * bulletPtrArray[], int countBullet, Asteroid * asteroidPtrArray[], int countAsteroid, Lives * livesPtrArray[], int lifeCount, RectangleShape &tens, RectangleShape &ones, RectangleShape &scoreHundredsSprite, RectangleShape &scoreTensSprite, RectangleShape &scoreOnesSprite);

//each update function updates values for the draw function
void updatePlayer(RectangleShape &player, Ship *ship);
void updatePlanet(RectangleShape &planet, Texture &planetTexture, Planet * planetVals, double &gameTime);
void updateBullet(Bullet * bullet);
void updateAsteroid(Asteroid * asteroid);
void updatePlanetLives(RectangleShape &tensSprite, RectangleShape &onesSprite, Texture &tens, Texture &ones, int lives);
void updateScore(RectangleShape &hundredsSprite, RectangleShape &tensSprite, RectangleShape &onesSprite, Texture &hundreds, Texture &tens, Texture &ones, int score);
void setLives(Lives * life, int lifeNum);

//makes asteroid harmless so animation can play, then handles movement of all pointers
void asteroidCollision(Asteroid * asteroidPtrArray[], int &countAsteroid, int currentAsteroid, Time animationSpeed);

#endif //include guard