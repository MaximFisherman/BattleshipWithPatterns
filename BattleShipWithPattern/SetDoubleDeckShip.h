#pragma once
#include "ShipArrangemen.h"
class SetDoubleDeckShip :
	public StateField
{
public:
	SetDoubleDeckShip(Field* fieldClass);
	void ShipDoubleDeckArrangement(int size, char field[][SIZE_FIELD], vector<int>* CoordinateShip);

	~SetDoubleDeckShip();
};

