#pragma once
#include "stdafx.h"
#include "Field.h"

using namespace std;

class Field;
class SetSingleDeckShip :
	public StateField
{
public:
	SetSingleDeckShip(Field* field);
	void ShipSingleDeckArrangement(int size, char field[][SIZE_FIELD], vector<int>* CoordinateShip);

	~SetSingleDeckShip();
};

