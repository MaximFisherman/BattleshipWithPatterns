#pragma once
#include "Field.h"
class FourDeckShip :
	public Field
{
public:
	FourDeckShip();
	~FourDeckShip();
protected:
	list<int> CoordinateShip;
};

