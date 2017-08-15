#pragma once
#include "GlobalVariables.h"
#include "Field.h"
#include <vector>


class ShipArrangemen
{
public:
	/*bool PlacingShip(
		int         size,
		bool        isHoriz,
		int         rowTop,
		int         colLeft,
		char  field[][SIZE_FIELD]
	);*/
    virtual void SetSingleDeck(Field *m);
	//virtual void SetDoubleDeck(Field *m);
};

