#pragma once
#include "stdafx.h"
#include "StateField.h"

using namespace std;

class Field
{
	class StateField *current;

public:
	Field();
	char field[SIZE_FIELD][SIZE_FIELD];
	
	vector<int> CoordinateSingleDeckShip;
	vector<int> CoordinateDoubleDeckShip;
	vector<int> CoordinateThreeDeckShip;
	vector<int> CoordinateFourDeckShip;

	void setCurrent(StateField *s);

	void setSingleDeckShip();
	void setDoubleDeckShip();
	void setThreeDeckShip();
	void setFourDeckShip();

	void ViewField();
	virtual ~Field();

	void shipArrangement();
};