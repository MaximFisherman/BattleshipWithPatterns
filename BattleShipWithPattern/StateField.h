#pragma once
#include "stdafx.h"
#include "Field.h"
class Field;
class StateField
{
public:
	StateField();
	virtual void setSingleDeckShip(Field* f);
	virtual ~StateField();
};

