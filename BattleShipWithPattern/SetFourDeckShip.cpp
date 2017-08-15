#include "stdafx.h"
#include "SetFourDeckShip.h"


SetFourDeckShip::SetFourDeckShip()
{
}

/*
void  SetFourDeckShip::ShipFourDeckArrangement(int  size, char  field[][SIZE_FIELD])
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
		}
	}
	else
	{
		for (int i = rowTop; i < rowTop + size; ++i)
		{
			field[i][colLeft] = SYMB_SHIP;// Centering vertical
		}
	}
}
*/
SetFourDeckShip::~SetFourDeckShip()
{
}
