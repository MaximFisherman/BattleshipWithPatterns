#pragma once
#include "Field.h"
class SingleDeckShip :
	public Field
{
public:
	SingleDeckShip();
	~SingleDeckShip();

	list<int> CoordinateShip;
};

