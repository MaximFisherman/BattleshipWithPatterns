#pragma once
#include "ShipArrangemen.h"
class SetDoubleDeckShip :
	public StateField
{
public:
	SetDoubleDeckShip(Field* field);
	void ShipDoubleDeckArrangement(int size, char field[][SIZE_FIELD], vector<int>* CoordinateShip);

	~SetDoubleDeckShip();
};

