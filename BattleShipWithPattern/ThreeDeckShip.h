#pragma once
#include "Field.h"
class ThreeDeckShip :
	public Field
{
public:
	ThreeDeckShip();
	~ThreeDeckShip();
protected:
	list<int> CoordinateShip;
};

