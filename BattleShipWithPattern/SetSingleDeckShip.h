#pragma once
#include "stdafx.h"
#include "Field.h"

using namespace std;


class SetSingleDeckShip :
	public StateField
{
public:
	SetSingleDeckShip();
	//void ShipSingleDeckArrangement(int size, char field[][SIZE_FIELD]);

	/*void use(void)
	{	
		Field fieldClass;
		for (int i = 0; i < 4; ++i)
		{
			ShipSingleDeckArrangement(1, fieldClass.field);
		}
		
		for (int i = 0; i < SIZE_FIELD; ++i)
		{
			for (int j = 0; j < SIZE_FIELD; ++j)
				cout << " " << fieldClass.field[i][j] << " ";
			cout << endl;
		}
		cout << "SINGLE DECK SET work" << endl;
	}*/
	~SetSingleDeckShip();
};

