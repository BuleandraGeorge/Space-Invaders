#include "Board.h";
#include <string>;

Board::Board()
{
	//General TEXTS

//HighScore and Score settings
	HighScore.set("HIGHSCORE: 0", Vector2f(550.f, 10.f));
	CurrentScore.set("SCORE: 0", Vector2f(70.f, 10.f));

	//Lives of player
	LivesNo.set("3", Vector2f(30.f, 550.f));
	LivesNo.theMessage.setCharacterSize(30);
	LivesImg.loadSprite("Ship.png", Vector2f(32.f, 25.f));
	LivesImg.sprite.setPosition(Vector2f(65.f, 565.f));

	//Bottom of the battlefield;

	Bottom.setFillColor(Color::Green);
	Bottom.setSize(Vector2f(800.f, 10.f));
	Bottom.setPosition(0.f, 590.f);

	//Next Round Screen
	NewEnemies.centered("NEW WAVE COMING! BE READY!!!", 200.f);

	//GAME OVER SCREEN
	GameOver.centered("GAME OVER!!!", 200.f);
	const float kfWidthGO = 400 - (GameOver.theMessage.getLocalBounds().width / 2);
	GOBackground.setFillColor(Color::Red);
	GOBackground.setSize(Vector2f(GameOver.theMessage.getLocalBounds().width + 10, GameOver.theMessage.getLocalBounds().height + 10));
	GOBackground.setPosition(Vector2f(kfWidthGO - 5, 205.f));

	PlayAgain.centered("PRESS SPACE TO PLAY AGAIN", 250.f);
	const float kfWidthPA = 400 - (PlayAgain.theMessage.getLocalBounds().width / 2);
	//background
	PABackground.setFillColor(Color::Red);
	PABackground.setSize(Vector2f(PlayAgain.theMessage.getLocalBounds().width + 15, PlayAgain.theMessage.getLocalBounds().height + 15));
	PABackground.setPosition(Vector2f(kfWidthPA - 5, 255.f));
	//PlayButton and Title settings

	PlayButton.centered("PLAY", 150.f);
	GameTitle.theMessage.setString("SPACE INVADERS");
	const float kfWidthGT = 400 - (GameTitle.theMessage.getLocalBounds().width / 2);
	GameTitle.theMessage.setPosition(Vector2f(kfWidthGT, 200.f));

	//Info Score Table Settings

	const float kfWidthImgAlighment = 300;
	const float kfWidthScoreAlighment = 325;
	//Red Invader Score
	RedScore.theMessage.setString(" - 100 POINTS");
	RedScore.theMessage.setPosition(Vector2f(kfWidthScoreAlighment, 300.f));
	RedInvader.loadSprite("RedInvader.png", Vector2f(32, 25));
	RedInvader.sprite.setPosition(Vector2f(kfWidthImgAlighment, 320.f));

	//Third Line Invader Score
	A3Score.theMessage.setString(" - 50 POINTS");
	A3Score.theMessage.setPosition(Vector2f(kfWidthScoreAlighment, 350.f));
	A3Image.loadSprite("InvaderC1.png", Vector2f(32, 25));
	A3Image.sprite.setPosition(Vector2f(kfWidthImgAlighment, 370.f));

	//Middle Line Invader Score
	A2Score.theMessage.setString(" - 30 POINTS");
	A2Score.theMessage.setPosition(Vector2f(kfWidthScoreAlighment, 400.f));
	A2Image.loadSprite("InvaderB1.png", Vector2f(32, 25));
	A2Image.sprite.setPosition(Vector2f(kfWidthImgAlighment, 420.f));

	//Front Line Invader Score
	A1Score.theMessage.setString(" - 10 POINTS");
	A1Score.theMessage.setPosition(Vector2f(kfWidthScoreAlighment, 450.f));
	A1Image.loadSprite("InvaderA1.png", Vector2f(32, 25));
	A1Image.sprite.setPosition(Vector2f(kfWidthImgAlighment, 470.f));
	///Music
	Intro.openFromFile(".\\assets\\\sounds\\intro_music.wav");
	Intro.setLoop(true);
	
	InGameMusic.openFromFile(".\\assets\\\sounds\\game_going.wav");
	InGameMusic.setLoop(true);
	InGameMusic.setVolume(35);

	GameOverMusic.openFromFile(".\\assets\\\sounds\\game_over.wav");
	GameOverMusic.setLoop(true);
	Intro.play();
}
void Board::drawInGameElements(RenderWindow& theWindow)
{
	theWindow.draw(LivesImg.sprite);
	theWindow.draw(LivesNo.theMessage);
	theWindow.draw(Bottom);
	theWindow.draw(HighScore.theMessage);
	theWindow.draw(CurrentScore.theMessage);
}
void Board::drawMenuElements(RenderWindow& theWindow)
{
	theWindow.draw(PlayButton.theMessage);
	theWindow.draw(GameTitle.theMessage);
	theWindow.draw(RedScore.theMessage);
	theWindow.draw(A1Score.theMessage);
	theWindow.draw(A2Score.theMessage);
	theWindow.draw(A3Score.theMessage);
	theWindow.draw(RedInvader.sprite);
	theWindow.draw(A1Image.sprite);
	theWindow.draw(A2Image.sprite);
	theWindow.draw(A3Image.sprite);
	theWindow.draw(HighScore.theMessage);
	theWindow.draw(CurrentScore.theMessage);
}

void Board::drawNextWaveScreen(RenderWindow& theWindow)
{
	theWindow.draw(HighScore.theMessage);
	theWindow.draw(CurrentScore.theMessage);
	theWindow.draw(NewEnemies.theMessage);
	theWindow.draw(LivesImg.sprite);
	theWindow.draw(LivesNo.theMessage);
	theWindow.draw(Bottom);
}
void Board::updateScore(int uInvaderLine)
{
	switch (uInvaderLine)
	{
	case 4:
		uiCurrentScore = uiCurrentScore + 100;
		break;
	case 3:
		uiCurrentScore = uiCurrentScore + 50;
		break;
	case 2:
		uiCurrentScore = uiCurrentScore + 30;
		break;
	case 1:
		uiCurrentScore = uiCurrentScore + 10;
		break;
	default:
		uiCurrentScore = 0;
		break;
	}
	if (uiCurrentScore > uiHighScore)
	{
		uiHighScore = uiCurrentScore;
	}
	CurrentScore.theMessage.setString("SCORE: " + std::to_string(uiCurrentScore));
	HighScore.theMessage.setString("HIGHSCORE: " + std::to_string(uiHighScore));
}
void Board::updateLives(int iNoLives)
{
	LivesNo.theMessage.setString(std::to_string(iNoLives));
}
void Board::drawGameOver(RenderWindow& thewindow)
{
	thewindow.draw(GOBackground);
	thewindow.draw(PABackground);
	thewindow.draw(GameOver.theMessage);
	thewindow.draw(PlayAgain.theMessage);
}