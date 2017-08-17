// BattleShipWithPattern.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Field.h"
#include "Move.h"

int main()
{
	Field field;
	Move move;
	field.shipArrangement();
	cout << "You field: " << endl;
	field.ViewFieldUser();

	cout << "Enemy Field" << endl;
	//system("cls");
	move.MoveUser(1,2, &field);
	move.MoveComputer(&field);

	system("cls");

	field.ViewFieldUser();
	field.ViewHiddenFieldEnemy();
	system("pause");
    return 0;
}

