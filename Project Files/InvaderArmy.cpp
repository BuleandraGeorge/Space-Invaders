#include "InvaderArmy.h";

InvaderArmy::InvaderArmy()
{
	float fXPosition;
	float fYPosition = 150;
	float fShipWidth;
	for (int i = 0; i <= 9; i++)
	{
		fShipWidth = FirstLine[i].kiXShipSize + 10.f ; // the width of the ship + 30 px gap to the right of the ship
		fXPosition = i * fShipWidth; //number of the invader in the line mutiplied by its size which displays them side by side
		fXPosition = fXPosition + 190; // to create space between invaders I added 170 px at the left side of each invader.
		FirstLine[i].sprite.setPosition(Vector2f(fXPosition, fYPosition));
		FirstLine[i].updateTexture("InvaderC1.png");
		SecondLine[i].updateTexture("InvaderB1.png");
		SecondLine[i].sprite.setPosition(Vector2f(fXPosition, fYPosition + 50));
		ThirdLine[i].updateTexture("InvaderA1.png");
		ThirdLine[i].sprite.setPosition(Vector2f(fXPosition, fYPosition + 100));

	}
	RedInvader.loadSound("InvaderHit.wav");
	bullet.loadSound("InvaderBullet.wav");
	RedInvader.updateTexture("RedInvader.png");
	RedInvader.sprite.setPosition(Vector2f(0.f, 75.f));
};
void InvaderArmy::drawArmy(RenderWindow &Window)
{
	
	for (int i = 0;i <= 9; i++)
	{
		FirstLine[i].drawEntity(Window);
		SecondLine[i].drawEntity(Window);
		ThirdLine[i].drawEntity(Window);
	};
	elapsedTime = timerRedInvader.getElapsedTime();
	if (elapsedTime.asSeconds() > 5)
	{
		RedInvader.drawEntity(Window);

		RedInvader.sprite.move(Vector2f(2, 0));
		if (RedInvader.sprite.getPosition().x > 800)
		{
			RedInvader.sprite.setPosition(Vector2f(0.f, 75.f));
			timerRedInvader.restart();
		}
				
	}			
}
int InvaderArmy::checkCollision(Sprite Object)
{
	if (RedInvader.collisionCheck(Object))
	{
		RedInvader.remove();
		return 4;
	}
	for (int i=0; i<10; i++)
	{
		if (FirstLine[i].collisionCheck(Object))
		{
			FirstLine[i].remove();
			RedInvader.theSound.play();
			return 3;
		}
		if (SecondLine[i].collisionCheck(Object))
		{
			SecondLine[i].remove();
			RedInvader.theSound.play();
			return 2;
		}
		if (ThirdLine[i].collisionCheck(Object))
		{
			ThirdLine[i].remove();
			RedInvader.theSound.play();
			return 1;
		}
	}
	return 0;
}
void InvaderArmy::shoot()
{
	bullet.bExists = true;
	srand(time(NULL));
	unsigned int uiNoInvader = rand() % 10;
	bool bExistInvaders;
	unsigned int iNoLine;
	do {
		iNoLine = rand() % 3 + 1;
		bExistInvaders = existInvadersOnLine(iNoLine);
	} while (!bExistInvaders);
		
	switch (iNoLine)
		{
		case 3:
		{

			while (ThirdLine[uiNoInvader].sprite.getScale().x == 0)
			{
				uiNoInvader = rand() % 10;
			}
			Vector2f EnemyPosition = ThirdLine[uiNoInvader].sprite.getPosition();
			bullet.set(EnemyPosition.x, EnemyPosition.y + 10);
			break;
		}
		case 2:
		{
			while (SecondLine[uiNoInvader].sprite.getScale().x == 0)
			{
				uiNoInvader = rand() % 10;
			}
			Vector2f EnemyPosition = SecondLine[uiNoInvader].sprite.getPosition();
			bullet.set(EnemyPosition.x, EnemyPosition.y + 10);
			break;
		}
		case 1:
		{
			while (FirstLine[uiNoInvader].sprite.getScale().x == 0)
			{
				uiNoInvader = rand() % 10;
			}
			Vector2f EnemyPosition = FirstLine[uiNoInvader].sprite.getPosition();
			bullet.set(EnemyPosition.x, EnemyPosition.y + 10);
			break;
		}
	}
	
}
void InvaderArmy::callNextWave()
{
	float fXPosition;
	float fYPosition = 150;
	float fShipWidth;
	for (int i = 0; i < 10; i++)
	{
		FirstLine[i].sprite.setScale(FirstLine[i].fWidth, FirstLine[i].fHeight);
		SecondLine[i].sprite.setScale(SecondLine[i].fWidth, SecondLine[i].fWidth);
		ThirdLine[i].sprite.setScale(ThirdLine[i].fWidth, ThirdLine[i].fWidth);
		fShipWidth = FirstLine[i].kiXShipSize + 10.f; // the width of the ship + 10 px gap to the right of the ship
		fXPosition = i * fShipWidth; //number of the invader in the line mutiplied by its size which displays them side by side
		fXPosition = fXPosition + 190; // to create space between invaders I added 170 px at the left side of each invader.
		FirstLine[i].sprite.setPosition(Vector2f(fXPosition, fYPosition));
		FirstLine[i].updateTexture("InvaderC1.png");
		SecondLine[i].updateTexture("InvaderB1.png");
		SecondLine[i].sprite.setPosition(Vector2f(fXPosition, fYPosition + 50));
		ThirdLine[i].updateTexture("InvaderA1.png");
		ThirdLine[i].sprite.setPosition(Vector2f(fXPosition, fYPosition + 100));
	}

	RedInvader.reset(RedInvader.fWidth, RedInvader.fHeight);
	RedInvader.sprite.setPosition(Vector2f(0, 75.f));
	timerRedInvader.restart();

}
void InvaderArmy::moveForward(bool bMoveForward)
{
	if (!bMoveForward)
	{
		if (bMoveRight)
		{
			for (int i = 0; i < 10; i++)
			{
				FirstLine[i].sprite.move(Vector2f(25.f, 0));
				SecondLine[i].sprite.move(Vector2f(25.f, 0));
				ThirdLine[i].sprite.move(Vector2f(25.f, 0));
			}
		}
		else
		{
			for (int i = 0; i < 10; i++)
			{
				FirstLine[i].sprite.move(Vector2f(-25.f, 0));
				SecondLine[i].sprite.move(Vector2f(-25.f, 0));
				ThirdLine[i].sprite.move(Vector2f(-25.f, 0));
			}
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			FirstLine[i].sprite.move(Vector2f(0, 50.f));
			SecondLine[i].sprite.move(Vector2f(0, 50.f));
			ThirdLine[i].sprite.move(Vector2f(0, 50.f));
		
		}
	}
	
}
int InvaderArmy::collideSides()
{
	int iNoInvader;
	float fYFLine;
	float fYSLine;
	float fYTLine;
	for (int i = 0; i < 10; i++)
	{
		if (bMoveRight)
		{
			iNoInvader = 9 - i;
			if (FirstLine[iNoInvader].sprite.getScale().x != 0)
			{
				float fXPosition = FirstLine[iNoInvader].sprite.getPosition().x;
				if (fXPosition > 700.f)
				{
					bMoveRight = false;
					return 1;
				}
			}
		}
		else
		{
			iNoInvader = i;
			if (FirstLine[iNoInvader].sprite.getScale().x != 0)
			{
				float fXPosition = FirstLine[iNoInvader].sprite.getPosition().x;
				if (fXPosition < 50.f)
				{
					bMoveRight = true;
					return 1;
				}
			}
		}
		//Next 3 ifs tests if one of the line of invaders hits bottom of the window
		fYTLine = ThirdLine[i].sprite.getPosition().y;
		if (fYTLine > 500)
		{
			return 2;
		}	
		fYSLine = SecondLine[i].sprite.getPosition().y;
		if (fYSLine > 500)
		{
			return 2;
		}
		fYFLine = FirstLine[i].sprite.getPosition().y;
		if (fYFLine > 500)
		{
			return 2;
		}
	}
	return 0;
}
bool InvaderArmy::move() 
{
	elapsedTime = timerInvaders.getElapsedTime();
	int bCollide;

	if (elapsedTime.asSeconds() > 1)
	{
		animate();
		bCollide = collideSides();
		if (bCollide == 0)
		{
			moveForward(false);
			timerInvaders.restart();
			return 0;
		}
		if (bCollide == 1)
		{
			moveForward(true);
			timerInvaders.restart();
			return 0;
		}
		if (bCollide == 2)
		{
			timerInvaders.restart();
			return 1;
		}
		
	}
	return 0;
}
void InvaderArmy::animate() 
{
	if (bFirstFrame)
	{
		for (int i = 0; i < 10; i++)
		{
			FirstLine[i].updateTexture("InvaderC2.png");
			SecondLine[i].updateTexture("InvaderB2.png");
			ThirdLine[i].updateTexture("InvaderA2.png");
		}
		bFirstFrame = !bFirstFrame;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			FirstLine[i].updateTexture("InvaderC1.png");
			SecondLine[i].updateTexture("InvaderB1.png");
			ThirdLine[i].updateTexture("InvaderA1.png");
		}
		bFirstFrame = !bFirstFrame;
	}
	
	
		
}
bool InvaderArmy::existInvadersOnLine(int iNoLine)
{
	switch (iNoLine)
	{
		case 3:
		{
			bool bExists = false;
			for (int i = 0; i < 10; i++)
			{
				if (ThirdLine[i].sprite.getScale().x != 0)
				{
					bExists = true;
					break;
				}
			}
			return bExists;
		}
		case 2:
		{
			bool bExists = false;
			for (int i = 0; i < 10; i++)
			{
				if (SecondLine[i].sprite.getScale().x != 0)
				{
					bExists = true;
					break;
				}
			}
			return bExists;
		}
		case 1:
		{
			bool bExists = false;
			for (int i = 0; i < 10; i++)
			{
				if (FirstLine[i].sprite.getScale().x != 0)
				{
					bExists = true;
					break;
				}
			}
			return bExists;
		}
		default:
		{
			cout << "Invader line invalid";
			return 0;
		}
	}
}