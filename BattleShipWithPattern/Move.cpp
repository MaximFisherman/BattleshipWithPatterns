#include "stdafx.h"
#include "Move.h"


Move::Move()
{
}

bool Move::MoveUser(int x, int y, Field* fieldClass)
{
	--x;
	--y;

	if (x > SIZE_FIELD || x < 0 || y > SIZE_FIELD || y < 0) {
		cout << "You are missed, you fire went beyond" << endl;
		return false;
	}

	if (fieldClass->fieldEnemy[y][x] == '$' || fieldClass->fieldEnemy[y][x] == 'X')
	{
		cout << "You already shot at this place" << endl;
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
					attak_ship = 1;
				}else{
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
