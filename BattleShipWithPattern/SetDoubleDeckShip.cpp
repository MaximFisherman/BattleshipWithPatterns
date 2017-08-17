#include "stdafx.h"
#include "SetDoubleDeckShip.h"


SetDoubleDeckShip::SetDoubleDeckShip(Field* fieldClass)
{
	srand(time(NULL));
	//add ship DoubleDeck on board
	for (int i = 0; i < 3; ++i)
	{
		ShipDoubleDeckArrangement(2, fieldClass->fieldUser, &fieldClass->CoordinateDoubleDeckShip);
		ShipDoubleDeckArrangement(2, fieldClass->fieldEnemy, &fieldClass->CoordinateDoubleDeckShipEnemy);
	}
}

void  SetDoubleDeckShip::ShipDoubleDeckArrangement(int  size, char  field[][SIZE_FIELD], vector<int>* CoordinateShip)
{
	bool  isHoris = rand() % 2 == 0;//If rand() % 2 == 0 return true 
	int   rowTop = 0;
	int   colLeft = 0;
	int	  count = 0;

	do
	{
		do
		{
			rowTop = rand() % SIZE_FIELD;// get random top cell width size 
		} while (!isHoris
			&& rowTop > SIZE_FIELD - size);

		do
		{
			colLeft = rand() % SIZE_FIELD;// get random size cell width size
		} while (isHoris
			&& colLeft > SIZE_FIELD - size);

	} while (!PlacingShip(size, isHoris, rowTop, colLeft, field));



	if (isHoris)
	{
		for (int j = colLeft; j < colLeft + size; ++j)
		{
			field[rowTop][j] = SYMB_SHIP;//Centering horizontally

										 //Add coordinate to vector 
			CoordinateShip->push_back(j);
			CoordinateShip->push_back(rowTop);
		}
	}
	else
	{
		for (int i = rowTop; i < rowTop + size; ++i)
		{
			field[i][colLeft] = SYMB_SHIP;// Centering vertical

										  //Add coordinate to vector 
			CoordinateShip->push_back(colLeft);
			CoordinateShip->push_back(i);
		}
	}
}


SetDoubleDeckShip::~SetDoubleDeckShip()
{
}
