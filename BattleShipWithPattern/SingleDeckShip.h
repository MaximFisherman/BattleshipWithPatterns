#pragma once
#include "Field.h"
class SingleDeckShip :
	public Field
{
public:
	SingleDeckShip();
	~SingleDeckShip();
protected:
	list<int> CoordinateShip;
};

