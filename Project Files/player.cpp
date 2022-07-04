#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include "player.h";
player::player()
{	fInitialX = 400 - sprite.getLocalBounds().width / 2;
	fInitialY = 530;
	loadSprite("Ship.png", Vector2f(35.f, 25.f));
	sprite.setPosition(Vector2f(fInitialX, fInitialY));
	bullet.bPositive = false;
	loadSound("ShipHit.wav");
	bullet.loadSound("ShipBullet.wav");

};
void player::moveRight()
{
	if (sprite.getPosition().x < 775)
	sprite.move(Vector2f(10.f, 0.f));
};
void player::moveLeft()
{
	if (sprite.getPosition().x > 25)
		sprite.move(Vector2f(-10.f, 0.f));
};
void player::shoot()
{
	if (!bullet.bExists)
	{	
		bullet.bExists = true;
		// it's position the position in front of the ship
		int iShipX = sprite.getPosition().x + 7;
		int iShipY = sprite.getPosition().y - 20;
		bullet.sprite.setColor(Color::Green);
		bullet.set(iShipX, iShipY);
		
	}
}
void player::resetPosition()
{
	sprite.setPosition(Vector2f(fInitialX, 530.f));
}
bool player::die()
{
	uiLives = uiLives - 1;
	AnimationTimer.restart();
	sprite.setColor(Color(255, 255, 255, 50));
	theSound.play();
	if (uiLives == 0)
	{
		sprite.setColor(Color::Red);
		return 1;
	}
		
	return 0;
}
bool player::distroied()
{
	uiLives = 1;
	return die();
}
void player::revive()
{
	resetPosition();
	uiLives = 3;
	sprite.setColor(Color::Green);
}
void player::drawEntity(RenderWindow &window)
{
	timeElapsed = AnimationTimer.getElapsedTime();
	if (timeElapsed.asSeconds() > 2)
	{
		sprite.setColor(Color(255, 255, 255, 255));
	}
	window.draw(sprite);
}
void player::move()
{
	switch (c_movingDirection)
	{
	case 'r':
		moveRight();
		break;
	case 'l':
		moveLeft();
		break;
	default:
		break;
	}
}
void player::setMovingDirection(char c_direction)
{
	c_movingDirection = c_direction;
}