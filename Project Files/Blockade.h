#pragma once
#include "Block.h";
class Blockade : public Block
{
	
public:
	// an array of Blocks;
	Block Block[3];
	// loads the block by setting the position
	Blockade();
	// logic for drawning the block in one go
	void drawBlockade(RenderWindow &Window);
	// checks if one of the blocks of blockade is hit return true for collision happend;
	bool checkCollision(Sprite Object);
	// resets the scale of the blocade
	void restoreBlockade();
};