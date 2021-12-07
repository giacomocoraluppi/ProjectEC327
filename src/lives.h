#ifndef LIVES //include guard
#define LIVES //include guard

#include <SFML/Graphics.hpp>

using namespace sf;

class Lives
{
	public:
		int size;
		int xLocation;
		int yLocation;
		
		RectangleShape livesSprite;
		Texture livesTexture;
		
		Lives();
};

#endif