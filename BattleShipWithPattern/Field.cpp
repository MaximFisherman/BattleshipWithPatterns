#include "stdafx.h"
#include "Field.h"
#include "SetSingleDeckShip.h"

Field::Field()
{
	current = new SetSingleDeckShip();
	/*for (int i = 0; i < SIZE_FIELD; i++)
	{
		for (int j = 0; j < SIZE_FIELD; j++)
		{
			field[i][j] = '*';
		}
	}*/
}


Field::~Field()
{
}

void Field::setSingleDeckShip()
{
	current->setSingleDeckShip(this);
}


/*
void Field::shipArrangement()
{
		
}
*/