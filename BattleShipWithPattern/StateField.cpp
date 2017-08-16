#include "stdafx.h"
#include "StateField.h"


StateField::StateField()
{
}

void StateField::setSingleDeckShip(Field* f)
{
	cout << "class StateField" << endl;
}

void StateField::setDoubleDeckShip(Field* f)
{
	cout << "class StateField" << endl;
}

void StateField::setThreeDeckShip(Field* f)
{
	cout << "class StateField" << endl;
}

void StateField::setFourDeckShip(Field* f)
{
	cout << "class StateField" << endl;
}

bool StateField::PlacingShip
(
	int         size,
	bool        isHoriz,
	int         rowTop,
	int         colLeft,
	char  field[][SIZE_FIELD]
)
{
	if (isHoriz)
	{
		for (int i = std::max(0, rowTop - 1);
			i <= std::min(SIZE_FIELD - 1, rowTop + 1);
			++i)
		{
			for (int j = std::max(0, colLeft - 1);
				j <= std::min(SIZE_FIELD - 1, colLeft + size);
				++j)
			{
				if (field[i][j] == SYMB_SHIP) return false; //If in this place is the ship we return false
			}
		}
		return  true;
	}
	else//Vertical
	{
		for (int i = std::max(0, rowTop - 1);
			i <= std::min(SIZE_FIELD - 1, rowTop + size);
			++i)
		{
			for (int j = std::max(0, colLeft - 1);
				j <= std::min(SIZE_FIELD - 1, colLeft + 1);
				++j)
			{
				if (field[i][j] == SYMB_SHIP) return false;
			}
		}
		return  true;
	}
}

StateField::~StateField()
{
}
