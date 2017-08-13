#pragma once
#include "Field.h" 

class DoubleDeckShip :
	public Field
{
public:
	DoubleDeckShip();
	~DoubleDeckShip();
protected:
	list<int> CoordinateShip;
};

