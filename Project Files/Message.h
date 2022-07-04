#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
//stores the font and the the actual text;
class Message
{
public:
	Font theFont;
	Text theMessage;

public:
	//loads and sets the font, sets a default size of 32 and the color white;
	Message();
	// updates the text accordingly to the parameters;
	void set(std::string theString, Vector2f thePosition);
	//sets, and center the text at the given height;
	void centered(std::string theSting, float fYPosition);

};