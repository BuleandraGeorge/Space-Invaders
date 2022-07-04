#include "Entity.h"

bool Entity::loadSprite(std::string sFileName, Vector2f fSize)
{
	bool bSuccess = texture.loadFromFile(".\\assets\\\images\\" + sFileName);

	if (!bSuccess)
	{
		std::cout << "I couldn't load the texture, please check the location of the texture." << std::endl;
		std::cout << "The location has to be .\\assets\\images\\my_texture.extension" << std::endl;
		return 0;
	}
	fWidth = fSize.x / texture.getSize().x;
	fHeight = fSize.y / texture.getSize().y;
	sprite.setScale(fWidth, fHeight);
	sprite.setOrigin(fSize.x / 2, fSize.y / 2);
	sprite.setTexture(texture);
	return 1;
}
bool Entity::updateTexture(std::string sFileName)
{
	bool bSuccess = texture.loadFromFile(".\\assets\\\images\\" + sFileName);

	if (!bSuccess)
	{
		std::cout << "I couldn't load the texture, please check the location of the texture." << std::endl;
		std::cout << "The location has to be .\\assests\\images\\my_texture.extension" << std::endl;
		return 0;
	}
	sprite.setTexture(texture);

	return 1;
}

bool Entity::loadSound(std::string fileName)
{
	bool bSuccess = soundBuffer.loadFromFile(".\\assets\\\sounds\\" + fileName);
	if (!bSuccess)
	{
		std::cout << "I couldn't load the sound, please check the location of the sound." << std::endl;
		std::cout << "The location has to be .\\assests\\sounds\\fileName" << std::endl;
		return 0;
	}
	theSound.setBuffer(soundBuffer);
	return 1;
}
void Entity::drawEntity(RenderWindow& window)
{
	window.draw(sprite);
}
bool Entity::collisionCheck(Sprite Object)
{
	if (sprite.getGlobalBounds().intersects(Object.getGlobalBounds()))
		return 1;
	return 0;
}
void Entity::remove()
{	//sets the scale to 0;
	sprite.setScale(Vector2f(0, 0));
}
void Entity::reset(float fWidth, float fHeight)
{
	sprite.setScale(Vector2f(fWidth, fHeight));
}