#pragma once
#include "Entity.h"
#include <string>
using namespace std;
// a simple invader, loads the random texture for begining;
class Invader : public Entity
{
public:
	const int kiXShipSize = 35; // width of invader
	const int kiYShipSize = 25; // height of invader
	Invader();
};