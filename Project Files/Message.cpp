#include "Message.h";

Message::Message()
{
	bool bSuccess = theFont.loadFromFile(".\\assets\\fonts\\unifont.ttf");
	theMessage.setFont(theFont);
	theMessage.setCharacterSize(32);
	theMessage.setFillColor(Color::White);
	
}
void Message::set(std::string theString, Vector2f thePosition)
{
	theMessage.setPosition(thePosition);
	theMessage.setString(theString);
}
void Message::centered(std::string theString, float fYPosition)
{
	theMessage.setString(theString);
	float fX = 400 - (theMessage.getLocalBounds().width / 2);
	theMessage.setPosition(Vector2f(fX, fYPosition));
}
