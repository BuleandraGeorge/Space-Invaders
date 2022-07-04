#pragma once
#include "SFML/Graphics.hpp";
#include "Message.h";
#include <string>;
#include "Entity.h";
using namespace sf;
/// Draws titles, texts and icons and other ornaments of the game
class Board
{
private:
	// texts 
	Message PlayButton;
	Message GameTitle;
	Message RedScore;
	Message A1Score;
	Message A2Score;
	Message A3Score;
	Message HighScore;
	Message CurrentScore;
	Message LivesNo;
	Message NewEnemies;
	Message GameOver;
	Message PlayAgain;
	// used to hold the sound for invaders' bullet;
	Entity RedInvader;
	// icons
	Entity A1Image;
	Entity A2Image;
	Entity A3Image;
	Entity LivesImg;
	// stores the scores;
	unsigned int uiHighScore = 0;
	unsigned int uiCurrentScore = 0;
	//background of texts;
	RectangleShape GOBackground;
	RectangleShape PABackground;
	
public:
	//main menu music
	Music Intro;
	//in game music
	Music InGameMusic;
	//game over music
	Music GameOverMusic;
	//the green line at the bottom of the window
	RectangleShape Bottom;

	Board();
	// draws elements of the fight screen
	void drawInGameElements(RenderWindow& Window);
	// draws elements specific for menu like play button, scores table;
	void drawMenuElements(RenderWindow& Window);
	// draws the text when the game is over; like text and the backgrounds' of the texts
	void drawGameOver(RenderWindow& Window);
	// prints the messages of next wave comming
	void drawNextWaveScreen(RenderWindow& Window);
	// keeps track of the scores and updates the strings in the messages;
	void updateScore(int iInvaderLine);
	// updates the text for live;
	void updateLives(int iNoLives);
};