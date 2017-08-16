#pragma once
#include "stdafx.h"
#include "ShipArrangemen.h"
using namespace std;

class SetFourDeckShip :
	public StateField
{
public:
	SetFourDeckShip(Field* field);
	void ShipFourDeckArrangement(int size, char field[][SIZE_FIELD], vector<int>* CoordinateShip);

	~SetFourDeckShip();
};

