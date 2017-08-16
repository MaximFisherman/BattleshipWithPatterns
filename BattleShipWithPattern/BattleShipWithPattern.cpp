// BattleShipWithPattern.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Field.h"

int main()
{
	Field field;
	field.shipArrangement();
	field.ViewField();
	system("pause");
    return 0;
}

