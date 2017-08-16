#pragma once
#include "stdafx.h"
#include "Field.h"
class Field;
class StateField
{
public:
	StateField();
	bool PlacingShip(
		int         size,
		bool        isHoriz,
		int         rowTop,
		int         colLeft,
		char  field[][SIZE_FIELD]
	);
	virtual void setSingleDeckShip(Field* f);
	virtual void setDoubleDeckShip(Field* f);
	virtual void setThreeDeckShip(Field* f);
	virtual void setFourDeckShip(Field* f);
	
	virtual ~StateField();
};

