#include "stdafx.h"
#include <windows.h>
#include "Move.h"


Move::Move()
{
}

template<typename FieldType>
void Move::Check—ondition(int x, int y, FieldType field[SIZE_FIELD][SIZE_FIELD])
{
	if (!((y - 1) < 0) && field[y - 1][x] != 'X')
		field[y - 1][x] = '$';
	if (!((y - 1) < 0) && !((x + 1) > SIZE_FIELD - 1))
		field[y - 1][x + 1] = '$';
	if (!((x + 1) > SIZE_FIELD - 1) && field[y][x + 1] != 'X')
		field[y][x + 1] = '$';
	if (!((y + 1) > SIZE_FIELD - 1) && !((x + 1) > SIZE_FIELD - 1))
		field[y + 1][x + 1] = '$';
	if (!((y + 1) > SIZE_FIELD - 1) && field[y + 1][x] != 'X')
		field[y + 1][x] = '$';
	if (!((y + 1) > SIZE_FIELD) && !((x - 1) < 0))
		field[y + 1][x - 1] = '$';
	if (!((x - 1) < 0) && field[y][x - 1] != 'X')
		field[y][x - 1] = '$';
	if (!((y - 1) < 0) && !((x - 1) < 0))
		field[y - 1][x - 1] = '$';
}

bool Move::CheckKillShipEnemy(Field* fieldClass)
{
	//Check Single deck ship
	for (int i = 0; i < fieldClass->CoordinateSingleDeckShipEnemy.size(); i += 2)
	{
		int y = fieldClass->CoordinateSingleDeckShipEnemy[i];
		int x = fieldClass->CoordinateSingleDeckShipEnemy[i + 1];		

		if (fieldClass->fieldEnemy[y][x] == 'X')
		{
			
			Check—ondition(x, y, fieldClass->fieldEnemy);
		}
	}

	//Check Double deck ship
	for (int i = 0; i < fieldClass->CoordinateDoubleDeckShipEnemy.size(); i += 4)
	{
		int flagDestroyShip = 0;

		int y = fieldClass->CoordinateDoubleDeckShipEnemy[i];
		int x = fieldClass->CoordinateDoubleDeckShipEnemy[i + 1];
		
		if (fieldClass->fieldEnemy[x][y] == 'X')
		{
			flagDestroyShip++;
		}


		int yTemp_1 = fieldClass->CoordinateDoubleDeckShipEnemy[i + 2];
		int xTemp_1 = fieldClass->CoordinateDoubleDeckShipEnemy[i + 3];
		
		if (fieldClass->fieldEnemy[xTemp_1][yTemp_1] == 'X')
		{
			flagDestroyShip++;
		}
		
		if (flagDestroyShip == 2)
		{
			Check—ondition(y, x, fieldClass->fieldEnemy);
			Check—ondition(yTemp_1, xTemp_1, fieldClass->fieldEnemy);
		}
	}
	return 0;
}

bool Move::CheckKillShipUser(Field* fieldClass)
{
	//Check Single deck ship
	for (int i = 0; i < fieldClass->CoordinateSingleDeckShip.size(); i += 2)
	{
		int y = fieldClass->CoordinateSingleDeckShip[i];
		int x = fieldClass->CoordinateSingleDeckShip[i + 1];

		if (fieldClass->fieldUser[y][x] == 'X')
		{
			Check—ondition(x, y, fieldClass->fieldUser);
		}
	}

	//Check Double deck ship
	for (int i = 0; i < fieldClass->CoordinateDoubleDeckShip.size(); i += 4)
	{
		int flagDestroyShip = 0;

		int y = fieldClass->CoordinateDoubleDeckShip[i];
		int x = fieldClass->CoordinateDoubleDeckShip[i + 1];

		if (fieldClass->fieldUser[x][y] == 'X')
		{
			flagDestroyShip++;
		}


		int yTemp_1 = fieldClass->CoordinateDoubleDeckShip[i + 2];
		int xTemp_1 = fieldClass->CoordinateDoubleDeckShip[i + 3];

		if (fieldClass->fieldUser[xTemp_1][yTemp_1] == 'X')
		{
			flagDestroyShip++;
		}

		if (flagDestroyShip == 2)
		{
			Check—ondition(y, x, fieldClass->fieldUser);
			Check—ondition(yTemp_1, xTemp_1, fieldClass->fieldUser);
		}
	}
	return 0;
}

bool Move::MoveUser(int x, int y, Field* fieldClass)
{
	--x;
	--y;
	CheckKillShipEnemy(fieldClass);
	if (x > SIZE_FIELD || x < 0 || y > SIZE_FIELD || y < 0) 
	{
		system("cls");
		cout << "You are missed, you fire went beyond" << endl;
		Sleep(4000);
		
		return false;
	}

	if (fieldClass->fieldEnemy[y][x] == '$' || fieldClass->fieldEnemy[y][x] == 'X')
	{
		system("cls");
		cout << "You already shot at this place" << endl;
		Sleep(4000);
		
		return false;
	}

	if (fieldClass->fieldEnemy[y][x] == '*') {
		fieldClass->hiddenFieldEnemy[y][x] = '$';
		fieldClass->fieldEnemy[y][x] = '$';
		return true;
	}

	if (fieldClass->fieldEnemy[y][x] == '#') {
		fieldClass->hiddenFieldEnemy[y][x] = 'X';
		fieldClass->fieldEnemy[y][x] = 'X';
		CheckKillShipEnemy(fieldClass);
		return false;
	}
}

bool Move::MoveComputer(Field* fieldClass)
{
	bool attak = 0;
	CheckKillShipUser(fieldClass);
	while (attak == 0)
	{
		int X_TEMP = rand() % 10;
		int Y_TEMP = rand() % 10;
		if (fieldClass->fieldUser[Y_TEMP][X_TEMP] == '$') attak = 1;
		if (fieldClass->fieldUser[Y_TEMP][X_TEMP] == 'X') attak = 1;
		if (fieldClass->fieldUser[Y_TEMP][X_TEMP] == '*') {
			attak = 0;
			fieldClass->fieldUser[Y_TEMP][X_TEMP] = '$';
			break;
		}

		if (fieldClass->fieldUser[Y_TEMP][X_TEMP] == '#') {
			fieldClass->fieldUser[Y_TEMP][X_TEMP] = 'X';
			bool attak_ship = 1;
			while (attak_ship == 0)
			{
				X_TEMP = rand() % X_TEMP + 2 + X_TEMP - 1;
				Y_TEMP = rand() % Y_TEMP + 2 + Y_TEMP - 1;
				if (fieldClass->fieldUser[Y_TEMP][X_TEMP] == '#') {
					fieldClass->fieldUser[Y_TEMP][X_TEMP] = 'X';
					//CheckKillShipUser(fieldClass);
					attak_ship = 1;
				}
				else {
					fieldClass->fieldUser[Y_TEMP][X_TEMP] = '$';
					attak_ship = 0; break;
				}
				attak = 0;
			}
		}
	}
	return true;
}

Move::~Move()
{
}
