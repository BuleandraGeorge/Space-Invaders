#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "entity.h";
#include "projectile.h"
using namespace sf;

class player : public Entity
{
public:
	projectile bullet;
	unsigned int uiLives = 3;
	Clock AnimationTimer;
	Clock Movement;
	Time timeElapsed;
	char c_movingDirection = 'n';
	// moves the ship right untill reaches the edge of the window
	void moveRight();
	// moves the ship right left reaches the edge of the window
	void moveLeft();

public:
	//loads the sprite, die sound, and sets the sound for the bullet on bullet.theSound;
	player();

	// sets the bullet with the current position and plays the sound 
	void shoot();
	// updates the lives of the player and plays the sound, return 0 or 1 for still alive or dead and change the color to red if no lifes left;
	bool die();
	// recenters the ship;
	void resetPosition();
	//resets the position, refill the lives, changes the color to green;
	void revive();
	// reduce the lives to 0 and calls die function;
	bool distroied();
	//animate when loose a life;
	void drawEntity(RenderWindow& window);
	//moves the player according to the parameters
	void move();
	void setMovingDirection(char c_mDirection);
};