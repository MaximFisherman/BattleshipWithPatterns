#pragma once
#include "stdafx.h"
#include "ShipArrangemen.h"
using namespace std;

class SetSingleDeckShip :
	public ShipArrangemen
{
public:
	SetSingleDeckShip();
	void use(void)
	{	
		cout << "Choise SetSingleDeckShip strategy" << endl;
		cout << "Method Placing ship returned: "  <<endl;
	}
	~SetSingleDeckShip();
};

