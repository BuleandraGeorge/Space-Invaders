#pragma once
#include <SFML/Graphics.hpp>
#include "Invader.h";
#include "projectile.h";
#include <stdlib.h>
#include <time.h>
// takes care of the generation, movement, collision, drawing and sounds for invaders army 
class InvaderArmy
{
	bool bMoveRight = true;

public:
	Invader FirstLine[10]; // first line of invaders bottom to top
	Invader SecondLine[10]; // second line of invaders bottom to top
	Invader ThirdLine[10]; // third line of invaders bottom to top
	Invader RedInvader;
	// clock for red invader respawn;
	Clock timerRedInvader;
	// clock for regular invader movement
	Clock timerInvaders;
	Time elapsedTime;
	// used to swap the texture for animation;
	bool bFirstFrame = true;
	projectile bullet;
public:
	//sets the position and textures for invaders
	InvaderArmy();
	// check every invader if has collied with the given sprite; 
	int checkCollision(Sprite Object);
    // picks a random invader and generates the bullet;
	void shoot();
	// resets the scale and the position of the invaders, 
	void callNextWave();
	//moves invaders forward accordingly to the parameter given, or left or right using private variable bMoveRight;
	void moveForward(bool bMoveForward);
	//choose where the invaders will move;
	bool move();
	//checks which side they invader army is going to collide returns values accordingly;
	int collideSides();
	// animates the invaders;
	void animate();
	// logic to draw all the invaders in one go to the given window;
	void drawArmy(RenderWindow& window);
	// checks if are invaders on the given line;
	bool existInvadersOnLine(int iNoLine);
	
};