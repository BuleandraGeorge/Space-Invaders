#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
using namespace sf;
// a general Class which holds basic functions and proprieties like sprites, textures, sounds;
class Entity {
	
public:
	float fInitialX; // x initial position
	float fInitialY; // y initial position
	Texture texture;
	Sprite sprite;
	SoundBuffer soundBuffer;
	Sound theSound;
	// entity x scale parameter
	float fWidth;
	//entity y scale parameter
	float fHeight; 
public:
	//loads the texture and the sprite, it sets the size;
	bool loadSprite(std::string sFileName, Vector2f fSize);
	//updates the current texture
	bool updateTexture(std::string sFileName);
	//loads the soundbuffer and the sound;
	bool loadSound(std::string fileName);
	//simply draws the entity to a given window;
	void drawEntity(RenderWindow& window);
	//checks collision with the given sprite using insersects;
	bool collisionCheck(Sprite Object);
	// sets the scale of entity  to 0;
	void remove();
	// rescale the entity accordingly the given values
	void reset(float fWidth, float fHeight);
};