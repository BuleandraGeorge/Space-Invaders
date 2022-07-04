#include "Blockade.h";
Blockade::Blockade()
{
	int iYPosition = 480;
	int iXPosition;
	for (int i = 0; i < 3; i++)
	{
		iXPosition = i * (Block[i].sprite.getGlobalBounds().width + 100); // 100 gap between blocks
		iXPosition = iXPosition + 285;
		Block[i].sprite.setPosition(Vector2f(iXPosition, iYPosition));
	}
}
void Blockade::drawBlockade(RenderWindow &Window)
{
	for (int i = 0; i < 3; i++)
	{
		Block[i].drawEntity(Window);
	}
	
}
bool Blockade::checkCollision(Sprite Object)
{
	
	for (int i = 0; i < 3; i++)
	{
		if (Block[i].sprite.getGlobalBounds().intersects(Object.getGlobalBounds()))
		{	
			Block[i].uiNoCollisions++;
			switch (Block[i].uiNoCollisions)
			{
				case 3:
				{
					Block[i].sprite.setScale(Vector2f(0, 0));
					return 1;
				}
				case 2:
				{
					Block[i].updateTexture("WeakBlock.png");
					return 1;
				}
				case 1:
				{
					Block[i].updateTexture("OkBlock.png");
					return 1;
				}
				default:
					break;
			}
			
		}
	}
	return 0;
}
void Blockade::restoreBlockade()
{
	for (int i = 0; i < 3; i++)
	{
		Block[i].uiNoCollisions = 0;
		Block[i].sprite.setScale(Vector2f(Block[i].fWidth, Block[i].fHeight));
		Block[i].updateTexture("FullBlock.png");
	}
}