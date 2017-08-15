#pragma once
#include "stdafx.h"
#include "StateField.h"
#include "GlobalVariables.h"
#include <vector>
using namespace std;

class Field
{
	class StateField *current;

public:
	Field();
	char field[SIZE_FIELD][SIZE_FIELD];

	void setCurrent(StateField *s)
	{
		current = s;
	}

	void setSingleDeckShip();

	virtual ~Field();
	//void shipArrangement();
};