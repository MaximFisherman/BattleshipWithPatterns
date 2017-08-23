#include "stdafx.h"
#include "Options.h"
#include <Windows.h>

Options::Options()
{
}

void Options::CalculateStatisticEnemy(
	Field* fieldClass,
	int* countSingleDeckShip,
	int* countDoubleDeckShip,
	int* countThreeDeckShip,
	int* countFourDeckShip
)
{
	//Check count Single Deck ship
	for (int i = 0; i < fieldClass->CoordinateSingleDeckShipEnemy.size(); i += 2)
	{
		int y = fieldClass->CoordinateSingleDeckShipEnemy[i];
		int x = fieldClass->CoordinateSingleDeckShipEnemy[i + 1];

		if (fieldClass->fieldEnemy[y][x] == 'X')
		{
			++*countSingleDeckShip;
		}
	}

	//Check count Double Deck ship
	for (int i = 0; i < fieldClass->CoordinateDoubleDeckShipEnemy.size(); i += 4)
	{
		int flagDestroyShip = 0;

		int y = fieldClass->CoordinateDoubleDeckShipEnemy[i];
		int x = fieldClass->CoordinateDoubleDeckShipEnemy[i + 1];
		
		if (fieldClass->fieldEnemy[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		y = fieldClass->CoordinateDoubleDeckShipEnemy[i + 2];
		x = fieldClass->CoordinateDoubleDeckShipEnemy[i + 3];
		
		if (fieldClass->fieldEnemy[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		if (flagDestroyShip == 2)
		{
			++*countDoubleDeckShip;
		}
	}

	//Check count Three Deck ship
	for (int i = 0; i < fieldClass->CoordinateThreeDeckShipEnemy.size(); i += 6)
	{
		int flagDestroyShip = 0;

		int y = fieldClass->CoordinateThreeDeckShipEnemy[i];
		int x = fieldClass->CoordinateThreeDeckShipEnemy[i + 1];
		
		if (fieldClass->fieldEnemy[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		y = fieldClass->CoordinateThreeDeckShipEnemy[i + 2];
		x = fieldClass->CoordinateThreeDeckShipEnemy[i + 3];
	
		if (fieldClass->fieldEnemy[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		y = fieldClass->CoordinateThreeDeckShipEnemy[i + 4];
		x = fieldClass->CoordinateThreeDeckShipEnemy[i + 5];

		if (fieldClass->fieldEnemy[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		if (flagDestroyShip == 3)
		{
			++*countThreeDeckShip;
		}
	}

	//Check count Four Deck ship
	for (int i = 0; i < fieldClass->CoordinateFourDeckShipEnemy.size(); i += 8)
	{
		int flagDestroyShip = 0;

		int y = fieldClass->CoordinateFourDeckShipEnemy[i];
		int x = fieldClass->CoordinateFourDeckShipEnemy[i + 1];
		
		if (fieldClass->fieldEnemy[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		y = fieldClass->CoordinateFourDeckShipEnemy[i + 2];
		x = fieldClass->CoordinateFourDeckShipEnemy[i + 3];
		
		if (fieldClass->fieldEnemy[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		y = fieldClass->CoordinateFourDeckShipEnemy[i + 4];
		x = fieldClass->CoordinateFourDeckShipEnemy[i + 5];
		
		if (fieldClass->fieldEnemy[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		y = fieldClass->CoordinateFourDeckShipEnemy[i + 6];
		x = fieldClass->CoordinateFourDeckShipEnemy[i + 7];
		
		if (fieldClass->fieldEnemy[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		if (flagDestroyShip == 4)
		{
			++*countFourDeckShip;
		}
	}
}

void Options::CalculateStatisticUser(
	Field* fieldClass,
	int* countSingleDeckShip,
	int* countDoubleDeckShip,
	int* countThreeDeckShip,
	int* countFourDeckShip
)
{
	//Check count Single Deck ship
	for (int i = 0; i < fieldClass->CoordinateSingleDeckShip.size(); i += 2)
	{
		int y = fieldClass->CoordinateSingleDeckShip[i];
		int x = fieldClass->CoordinateSingleDeckShip[i + 1];

		if (fieldClass->fieldUser[y][x] == 'X')
		{
			++*countSingleDeckShip;
		}
	}

	//Check count Double Deck ship
	for (int i = 0; i < fieldClass->CoordinateDoubleDeckShip.size(); i += 4)
	{
		int flagDestroyShip = 0;

		int y = fieldClass->CoordinateDoubleDeckShip[i];
		int x = fieldClass->CoordinateDoubleDeckShip[i + 1];

		if (fieldClass->fieldUser[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		y = fieldClass->CoordinateDoubleDeckShip[i + 2];
		x = fieldClass->CoordinateDoubleDeckShip[i + 3];

		if (fieldClass->fieldUser[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		if (flagDestroyShip == 2)
		{
			++*countDoubleDeckShip;
		}
	}

	//Check count Three Deck ship
	for (int i = 0; i < fieldClass->CoordinateThreeDeckShip.size(); i += 6)
	{
		int flagDestroyShip = 0;

		int y = fieldClass->CoordinateThreeDeckShip[i];
		int x = fieldClass->CoordinateThreeDeckShip[i + 1];

		if (fieldClass->fieldUser[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		y = fieldClass->CoordinateThreeDeckShip[i + 2];
		x = fieldClass->CoordinateThreeDeckShip[i + 3];

		if (fieldClass->fieldUser[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		y = fieldClass->CoordinateThreeDeckShip[i + 4];
		x = fieldClass->CoordinateThreeDeckShip[i + 5];

		if (fieldClass->fieldUser[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		if (flagDestroyShip == 3)
		{
			++*countThreeDeckShip;
		}
	}

	//Check count Four Deck ship
	for (int i = 0; i < fieldClass->CoordinateFourDeckShip.size(); i += 8)
	{
		int flagDestroyShip = 0;

		int y = fieldClass->CoordinateFourDeckShip[i];
		int x = fieldClass->CoordinateFourDeckShip[i + 1];
		
		if (fieldClass->fieldUser[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		y = fieldClass->CoordinateFourDeckShip[i + 2];
		x = fieldClass->CoordinateFourDeckShip[i + 3];
		
		if (fieldClass->fieldUser[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		y = fieldClass->CoordinateFourDeckShip[i + 4];
		x = fieldClass->CoordinateFourDeckShip[i + 5];
		
		if (fieldClass->fieldUser[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		y = fieldClass->CoordinateFourDeckShip[i + 6];
		x = fieldClass->CoordinateFourDeckShip[i + 7];
		
		if (fieldClass->fieldUser[x][y] == 'X')
		{
			flagDestroyShip++;
		}

		if (flagDestroyShip == 4)
		{
			++*countFourDeckShip;
		}
	}
}

void Options::ViewStatistic(Field* field)
{
	int countSingleDeckShipEnemy = 0;
	int countDoubleDeckShipEnemy = 0;
	int countThreeDeckShipEnemy = 0;
	int countFourDeckShipEnemy = 0;

	int countSingleDeckShipUser = 0;
	int countDoubleDeckShipUser = 0;
	int countThreeDeckShipUser = 0;
	int countFourDeckShipUser = 0;

	CalculateStatisticEnemy(field, &countSingleDeckShipEnemy, &countDoubleDeckShipEnemy, &countThreeDeckShipEnemy, &countFourDeckShipEnemy);
	CalculateStatisticUser(field, &countSingleDeckShipUser, &countDoubleDeckShipUser, &countThreeDeckShipUser, &countFourDeckShipUser);
	
	system("cls");
	while (true)
	{
		cout << "For exit from the menu Statistic, please press Backspace button on your keyboard" << endl;
		cout << endl;
		cout << "----------------------------------------- " << endl;
		cout << "|" << "Single deck ship enemy destroy: " << countSingleDeckShipEnemy << "|" << endl;
		cout << "|" << "Double deck ship enemy destroy: " << countDoubleDeckShipEnemy << "|" << endl;
		cout << "|" << "Three deck ship enemy destroy:  " << countThreeDeckShipEnemy << "|" << endl;
		cout << "|" << "Four deck ship enemy destroy:   " << countFourDeckShipEnemy << "|" << endl;
		cout << "----------------------------------------- " << endl;

		cout << "----------------------------------------- " << endl;
		cout << "|" << "Single deck your ship destroy: " << countSingleDeckShipUser << "|" << endl;
		cout << "|" << "Double deck your ship destroy: " << countDoubleDeckShipUser << "|" << endl;
		cout << "|" << "Three deck your ship destroy:  " << countThreeDeckShipUser << "|" << endl;
		cout << "|" << "Four deck your ship destroy:   " << countFourDeckShipUser << "|" << endl;
		cout << "----------------------------------------- " << endl;
		Sleep(2000);

		system("cls");

		if (GetAsyncKeyState(VK_BACK)) break;//Exit loop left shift
	}
}

void Options::Pause()
{
	system("cls");
	while (true)
	{
		cout << "For exit from the pause menu, please press Backspace button on your keyboard" << endl;
		Sleep(1000);

			if (GetAsyncKeyState(VK_BACK)) break;//Exit loop backspase
			
			system("cls");
			time_t seconds = time(NULL);
			tm* timeinfo = localtime(&seconds);

		cout << "Current Datetime:" << asctime(timeinfo);
	}
}

Options::~Options()
{
}
