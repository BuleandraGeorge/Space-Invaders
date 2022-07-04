#pragma once
#include "entity.h";
class projectile: public Entity
{
public:
	//sets the sprite of the bullet
	projectile();
	//used to test if it is already an bullet in the air 
	bool bExists = false;
	// used to set the direction of the bullet upside or downside
	bool bPositive = true;
	// used to draw and to make it to move
	void drawTo(RenderWindow &window);
	// sets the position of the bullet and plays the specific sound
	void set(float fXPosition, float fYPosition);
	
};