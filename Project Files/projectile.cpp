#include "projectile.h";

projectile::projectile()
{
	loadSprite("Bullet.png", Vector2f(5, 10));
	
};
void projectile::drawTo(RenderWindow &window)
{
	//draws the bullet, sets the direction and speed of the bullet and check for end of the screen.
	drawEntity(window);
	if (bPositive)
	{
		sprite.move(Vector2f(0.f, 5.f));
		if (sprite.getPosition().y > 600)
			bExists = false;
	}
	else
	{
		sprite.move(Vector2f(0.f, -5.f));
		if (sprite.getPosition().y < 0)
			bExists = false;
	}
}
void projectile::set(float fXPosition, float fYPosition)
{
	sprite.setScale(fWidth, fHeight);
	sprite.setPosition(fXPosition, fYPosition);
	theSound.play();
}