#include <SFML/Graphics.hpp>
#include "player.h";
#include "projectile.h";
#include "InvaderArmy.h"
#include "Blockade.h";
#include "Board.h"
#include <string>
using namespace sf;

int main() {
	RenderWindow mainWindow(VideoMode(800, 600), "Space Invaders");
	mainWindow.setFramerateLimit(60);
	player ship;
	InvaderArmy invaders;
	Blockade blockade;
	Board theboard;
	bool bMainMenu = true;
	string sAStringHolder;
	bool bExitsInvaders;
	int iLineNo;
	bool bGameOver = false;
	Clock timer;
	sf::Time elapsedTime;

	while (mainWindow.isOpen()) 
	{
		Event event;
		while (mainWindow.pollEvent(event))
		{   
			switch (event.key.code)
			{
			case Keyboard::Right:
				if (event.type == Event::KeyPressed)
				{
					if (!bGameOver) ship.setMovingDirection('r');
					break;
				}
				ship.setMovingDirection('n');
				break;
			case Keyboard::Left:
				if (event.type == Event::KeyPressed)
				{
					if (!bGameOver) ship.setMovingDirection('l');
					break;
				}
				ship.setMovingDirection('n');
				break;
			default:break;
			}
			switch (event.type)
			{
				case Event::KeyPressed:
					switch (event.key.code)
					{
						case Keyboard::Space:
						{	
							if (bMainMenu)
							{	//starts the game
								bMainMenu = false;
								theboard.Intro.stop();
								theboard.InGameMusic.play();
							}
							else
							{
								// restarts the game
								if (bGameOver)
								{
									bGameOver = false;
									theboard.InGameMusic.play();
									blockade.restoreBlockade();
									invaders.callNextWave();
									ship.revive();
									theboard.updateScore(0);
									theboard.updateLives(3);
								}
								else
									// shoots 
									ship.shoot();
							}				
								break;
						}
						case Keyboard::Escape:
						{		//pause the game;
								theboard.Intro.play();
								theboard.InGameMusic.stop();
								theboard.GameOverMusic.stop();
								bMainMenu = true;
								break;
						}
						default:
							break;
					}
					/*
				case Event::KeyReleased:
				{
					switch (event.key.code)
					{
					case Keyboard::Right:
						if (!bGameOver) ship.setMovingDirection('n');
						break;
					case Keyboard::Left:
						if (!bGameOver) ship.setMovingDirection('n');
						break;
					default:
						break;
					}
				}
				*/
				default:
					break;
			}
				
			if (event.type == Event::Closed)
				mainWindow.close();
		}
		mainWindow.clear(Color::Black);
		if (!bMainMenu) {
			
			if (!bGameOver)
			{	
				theboard.GameOverMusic.stop();
				ship.move();
				for (int i = 1; i < 4; i++) {
					bExitsInvaders = invaders.existInvadersOnLine(i);
					if (bExitsInvaders)
						break;
				}
				// if invaders exits
				if (bExitsInvaders)
				{	//move the invades
					if (invaders.move())
					{	// tests if they reached the bottom of the screen
						bGameOver = ship.distroied();
						theboard.InGameMusic.stop();
						theboard.GameOverMusic.play();
					}
					// test if the player shooted
					if (ship.bullet.bExists)
					{	// draw the bullet
						ship.bullet.drawTo(mainWindow);
						iLineNo = invaders.checkCollision(ship.bullet.sprite);
						// if an enemy dead
						if (iLineNo != 0) 
						{	// updates the score
							theboard.updateScore(iLineNo);
							ship.bullet.bExists = false;
							ship.bullet.remove();
						}
						// if blockade hit, 
						if (blockade.checkCollision(ship.bullet.sprite))
						{
							ship.bullet.bExists = false;
							ship.bullet.remove();
						};

					}
					// if invaders hits the player
					if (invaders.checkCollision(ship.sprite))
					{ //game over
						bGameOver = ship.distroied();
						theboard.InGameMusic.stop();
						theboard.GameOverMusic.play();
					}
					// if invaders shooted
					if (invaders.bullet.bExists)
					{
						invaders.bullet.drawTo(mainWindow);
						bool bShipHitted = ship.collisionCheck(invaders.bullet.sprite);
						// if player hitted
						if (bShipHitted)
						{
							bGameOver = ship.die();
							//if game is over play the music
							if (bGameOver)
							{	
								theboard.InGameMusic.stop();
								theboard.GameOverMusic.play();
							}
							// updates the lives and remove the bullet
							theboard.updateLives(ship.uiLives);
							invaders.bullet.bExists = false;
							invaders.bullet.remove();
						}
						// is blockade is hitted
						bool bBlockadeHitted = blockade.checkCollision(invaders.bullet.sprite);
						if (bBlockadeHitted)
						{	// remove the bullet
							invaders.bullet.bExists = false;
							invaders.bullet.remove();

						};
					}
					else
					{	// if invaders bullet doesnt exist then shoot
						invaders.shoot();
					}
					//draw the invaders, blockades, ship, board and reset the timer for game over screen;
					invaders.drawArmy(mainWindow);
					blockade.drawBlockade(mainWindow);
					ship.drawEntity(mainWindow);
					theboard.drawInGameElements(mainWindow);
					timer.restart();
				}
				else
				{
					// if all the invaders all dead
					elapsedTime = timer.getElapsedTime();
					theboard.drawNextWaveScreen(mainWindow);
					// wait for 3 seconds before to call next wave;
					if (elapsedTime.asSeconds() > 3.0f)
					{
						theboard.GameOverMusic.stop();
						theboard.InGameMusic.play();
						blockade.restoreBlockade();
						invaders.callNextWave();
						ship.resetPosition();
					}
				}
			}
			else
			{	// if the game is over - the player lost - play the Game Over screen;
				invaders.drawArmy(mainWindow);
				blockade.drawBlockade(mainWindow);
				ship.drawEntity(mainWindow);
				theboard.drawInGameElements(mainWindow);
				theboard.drawGameOver(mainWindow);
			}
		}
		else
		{
			//draw the main menu screen
			theboard.drawMenuElements(mainWindow);
		}
		
		mainWindow.display();
		
	}

}
