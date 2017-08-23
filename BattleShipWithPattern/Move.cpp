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

			Check—ondition(y, x, fieldClass->hiddenFieldEnemy);
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

			Check—ondition(y, x, fieldClass->hiddenFieldEnemy);
			Check—ondition(yTemp_1, xTemp_1, fieldClass->hiddenFieldEnemy);
		}
	}

	//Check Three deck ship
	for (int i = 0; i < fieldClass->CoordinateThreeDeckShipEnemy.size(); i += 6)
	{
		int flagDestroyShip = 0;

		int y = fieldClass->CoordinateThreeDeckShipEnemy[i];
		int x = fieldClass->CoordinateThreeDeckShipEnemy[i + 1];

		if (fieldClass->fieldEnemy[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		int yTemp_1 = fieldClass->CoordinateThreeDeckShipEnemy[i + 2];
		int xTemp_1 = fieldClass->CoordinateThreeDeckShipEnemy[i + 3];

		if (fieldClass->fieldEnemy[xTemp_1][yTemp_1] == 'X')
		{
			flagDestroyShip++;
		}

		int yTemp_2 = fieldClass->CoordinateThreeDeckShipEnemy[i + 4];
		int xTemp_2 = fieldClass->CoordinateThreeDeckShipEnemy[i + 5];

		if (fieldClass->fieldEnemy[xTemp_2][yTemp_2] == 'X')
		{
			flagDestroyShip++;
		}

		if (flagDestroyShip == 3)
		{
			Check—ondition(y, x, fieldClass->fieldEnemy);
			Check—ondition(yTemp_1, xTemp_1, fieldClass->fieldEnemy);
			Check—ondition(yTemp_2, xTemp_2, fieldClass->fieldEnemy);

			Check—ondition(y, x, fieldClass->hiddenFieldEnemy);
			Check—ondition(yTemp_1, xTemp_1, fieldClass->hiddenFieldEnemy);
			Check—ondition(yTemp_2, xTemp_2, fieldClass->hiddenFieldEnemy);
		}
	}


	//Check Four deck ship
	for (int i = 0; i < fieldClass->CoordinateFourDeckShipEnemy.size(); i += 8)
	{
		int flagDestroyShip = 0;

		int y = fieldClass->CoordinateFourDeckShipEnemy[i];
		int x = fieldClass->CoordinateFourDeckShipEnemy[i + 1];

		if (fieldClass->fieldEnemy[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		int yTemp_1 = fieldClass->CoordinateFourDeckShipEnemy[i + 2];
		int xTemp_1 = fieldClass->CoordinateFourDeckShipEnemy[i + 3];

		if (fieldClass->fieldEnemy[xTemp_1][yTemp_1] == 'X')
		{
			flagDestroyShip++;
		}

		int yTemp_2 = fieldClass->CoordinateFourDeckShipEnemy[i + 4];
		int xTemp_2 = fieldClass->CoordinateFourDeckShipEnemy[i + 5];

		if (fieldClass->fieldEnemy[xTemp_2][yTemp_2] == 'X')
		{
			flagDestroyShip++;
		}

		int yTemp_3 = fieldClass->CoordinateFourDeckShipEnemy[i + 6];
		int xTemp_3 = fieldClass->CoordinateFourDeckShipEnemy[i + 7];

		if (fieldClass->fieldEnemy[xTemp_3][yTemp_3] == 'X')
		{
			flagDestroyShip++;
		}

		if (flagDestroyShip == 4)
		{
			Check—ondition(y, x, fieldClass->fieldEnemy);
			Check—ondition(yTemp_1, xTemp_1, fieldClass->fieldEnemy);
			Check—ondition(yTemp_2, xTemp_2, fieldClass->fieldEnemy);
			Check—ondition(yTemp_3, xTemp_3, fieldClass->fieldEnemy);

			Check—ondition(y, x, fieldClass->hiddenFieldEnemy);
			Check—ondition(yTemp_1, xTemp_1, fieldClass->hiddenFieldEnemy);
			Check—ondition(yTemp_2, xTemp_2, fieldClass->hiddenFieldEnemy);
			Check—ondition(yTemp_3, xTemp_3, fieldClass->hiddenFieldEnemy);
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

	//Check Three deck ship
	for (int i = 0; i < fieldClass->CoordinateThreeDeckShip.size(); i += 6)
	{
		int flagDestroyShip = 0;

		int y = fieldClass->CoordinateThreeDeckShip[i];
		int x = fieldClass->CoordinateThreeDeckShip[i + 1];

		if (fieldClass->fieldUser[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		int yTemp_1 = fieldClass->CoordinateThreeDeckShip[i + 2];
		int xTemp_1 = fieldClass->CoordinateThreeDeckShip[i + 3];

		if (fieldClass->fieldUser[xTemp_1][yTemp_1] == 'X')
		{
			flagDestroyShip++;
		}

		int yTemp_2 = fieldClass->CoordinateThreeDeckShip[i + 4];
		int xTemp_2 = fieldClass->CoordinateThreeDeckShip[i + 5];

		if (fieldClass->fieldUser[xTemp_2][yTemp_2] == 'X')
		{
			flagDestroyShip++;
		}

		if (flagDestroyShip == 3)
		{
			Check—ondition(y, x, fieldClass->fieldUser);
			Check—ondition(yTemp_1, xTemp_1, fieldClass->fieldUser);
			Check—ondition(yTemp_2, xTemp_2, fieldClass->fieldUser);
		}
	}

	//Check Four deck ship
	for (int i = 0; i < fieldClass->CoordinateFourDeckShip.size(); i += 8)
	{
		int flagDestroyShip = 0;

		int y = fieldClass->CoordinateFourDeckShip[i];
		int x = fieldClass->CoordinateFourDeckShip[i + 1];

		if (fieldClass->fieldUser[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		int yTemp_1 = fieldClass->CoordinateFourDeckShip[i + 2];
		int xTemp_1 = fieldClass->CoordinateFourDeckShip[i + 3];

		if (fieldClass->fieldUser[xTemp_1][yTemp_1] == 'X')
		{
			flagDestroyShip++;
		}

		int yTemp_2 = fieldClass->CoordinateFourDeckShip[i + 4];
		int xTemp_2 = fieldClass->CoordinateFourDeckShip[i + 5];

		if (fieldClass->fieldUser[xTemp_2][yTemp_2] == 'X')
		{
			flagDestroyShip++;
		}

		int yTemp_3 = fieldClass->CoordinateFourDeckShip[i + 6];
		int xTemp_3 = fieldClass->CoordinateFourDeckShip[i + 7];

		if (fieldClass->fieldUser[xTemp_3][yTemp_3] == 'X')
		{
			flagDestroyShip++;
		}

		if (flagDestroyShip == 4)
		{
			Check—ondition(y, x, fieldClass->fieldUser);
			Check—ondition(yTemp_1, xTemp_1, fieldClass->fieldUser);
			Check—ondition(yTemp_2, xTemp_2, fieldClass->fieldUser);
			Check—ondition(yTemp_3, xTemp_3, fieldClass->fieldUser);
		}
	}
	return 0;
}

bool Move::MoveUser(int x, int y, Field* fieldClass)
{
	--x;
	--y;
	
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
					CheckKillShipUser(fieldClass);
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
	CheckKillShipUser(fieldClass);
	return true;
}

bool Move::CheckVictory(Field* fieldClass)
{
	int flag = 0;
	int humanFlag = 0;
	int computerFlag = 0;
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<10; j++)
		{
			if (fieldClass->fieldUser[i][j] == '#')
				humanFlag = 1; // User have ship
			if (fieldClass->fieldEnemy[i][j] == '#')
				computerFlag = 1; // Computer opponent have ship
		}
	}
	if (humanFlag == 0)
		flag = 2;
	if (computerFlag == 0)
		flag = 1;
	if (flag == 1)
	{
		cout << "You win!\n";
		return true;
	}

	if (flag == 2)
	{
		cout << "Computer win!\n";
		return true;
	}
	return false;
}

Move::~Move()
{
}
