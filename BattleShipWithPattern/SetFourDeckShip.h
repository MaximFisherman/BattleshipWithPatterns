#pragma once
#include "stdafx.h"
#include "ShipArrangemen.h"
using namespace std;

//extern char field[SIZE_FIELD][SIZE_FIELD];

class SetFourDeckShip :
	public ShipArrangemen
{
public:
	SetFourDeckShip();
	/*void ShipFourDeckArrangement(int size, char field[][SIZE_FIELD]);
	void use(void)
	{
		for (int i = 0; i < 1; ++i)
		{
			ShipFourDeckArrangement(4, GlobalVaribles::field);
		}

		for (int i = 0; i < SIZE_FIELD; ++i)
		{
			for (int j = 0; j < SIZE_FIELD; ++j)
				cout << " " << GlobalVaribles::field[i][j] << " ";
			cout << endl;
		}
		cout << "FOUR DECK SET work" << endl;
	}*/
	~SetFourDeckShip();
};

