#include "stdafx.h"
#include "Field.h"
#include "SetSingleDeckShip.h"

Field::Field()
{
}


Field::~Field()
{
}

void Field::shipArrangement()
{
	Field field;
	SetSingleDeckShip setSingleDeckShip;

	field.setStrategy(&setSingleDeckShip);
	field.useStrategy();
}

void Field::useStrategy(void)
{
	operation->use();
	cout << "useStrategy is work"<<endl;
}

void Field::setStrategy(ShipArrangemen* shipArrangement)
{
	operation = shipArrangement;
}