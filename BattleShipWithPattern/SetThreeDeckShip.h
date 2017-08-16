#pragma once
#include "ShipArrangemen.h"
class SetThreeDeckShip :
	public StateField
{
public:
	SetThreeDeckShip(Field* field);
	void ShipThreeDeckArrangement(int size, char field[][SIZE_FIELD], vector<int>* CoordinateShip);

	~SetThreeDeckShip();
};

