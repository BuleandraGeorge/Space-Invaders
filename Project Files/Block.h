#pragma once
#include "Entity.h";
// a simple block;
class Block : public Entity
{
public:
	unsigned int uiNoCollisions = 0;
	Block();
};