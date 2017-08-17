#include "stdafx.h"
#include "Field.h"
#include "SetSingleDeckShip.h"
#include "SetDoubleDeckShip.h"
#include "SetThreeDeckShip.h"
#include "SetFourDeckShip.h"

Field::Field()
{
	//Initialization fieldUser
	for (int i = 0; i < SIZE_FIELD; i++)
	{
		for (int j = 0; j < SIZE_FIELD; j++)
		{
			fieldUser[i][j] = '*';
		}
	}

	//Initialization fieldEnemy
	for (int i = 0; i < SIZE_FIELD; i++)
	{
		for (int j = 0; j < SIZE_FIELD; j++)
		{
			fieldEnemy[i][j] = '*';
		}
	}

	//Initialization hiddenFieldEnemy
	for (int i = 0; i < SIZE_FIELD; i++)
	{
		for (int j = 0; j < SIZE_FIELD; j++)
		{
			hiddenFieldEnemy[i][j] = '0';
		}
	}
}

void Field::shipArrangement()
{
	current = new SetFourDeckShip(this);
	current = new SetThreeDeckShip(this);
	current = new SetDoubleDeckShip(this);
	current = new SetSingleDeckShip(this);
}

void Field::ViewFieldUser()
{
	for (int i = 0; i < SIZE_FIELD; i++)
	{
		for (int j = 0; j < SIZE_FIELD; j++)
		{
			cout << " " << fieldUser[i][j];
		}
		cout << endl;
	}
}

void Field::ViewFieldEnemy()
{
	for (int i = 0; i < SIZE_FIELD; i++)
	{
		for (int j = 0; j < SIZE_FIELD; j++)
		{
			cout << " " << fieldEnemy[i][j];
		}
		cout << endl;
	}
}

void Field::ViewHiddenFieldEnemy()
{
	for (int i = 0; i < SIZE_FIELD; i++)
	{
		for (int j = 0; j < SIZE_FIELD; j++)
		{
			cout << " " << hiddenFieldEnemy[i][j];
		}
		cout << endl;
	}
}

void Field::setCurrent(StateField *s)
{
	current = s;
}

void Field::setSingleDeckShip()
{
	current->setSingleDeckShip(this);
}

void Field::setDoubleDeckShip()
{
	current->setThreeDeckShip(this);
}

void Field::setThreeDeckShip()
{
	current->setThreeDeckShip(this);
}

void Field::setFourDeckShip()
{
	current->setFourDeckShip(this);
}

Field::~Field()
{

}

/*
void Field::shipArrangement()
{
		
}
*/