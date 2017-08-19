#include "stdafx.h"
#include "Game.h"
#include <Windows.h>

Game::Game()
{
}

void Game::Run()
{
	Field field;
	Move move;
	Options options;

	int countIteration = 0;
	int x = 0;
	int y = 0;
	int action = 0;


	while (true)
	{
		if (countIteration == 0)
		{
			field.shipArrangement();
		}
		system("cls");
		

		cout << " Your field " << endl;
			field.ViewFieldUser();
		cout << "Field your opponent" << endl;
			field.ViewFieldEnemy();
		
		cout << "Input 1 for play, input 2 for pause, input 3 for view statistic " << endl;
			cin >> action;

		if (action == 2)
		{
			options.Pause();
		}

		if (action == 3)
		{
			options.ViewStatistic(&field);
		}

		system("cls");

		cout << " Your field " << endl;
			field.ViewFieldUser();
		cout << "Field your opponent" << endl;
			field.ViewHiddenFieldEnemy();

		cout << "Input x:"; cin >> x; cout << endl;
		cout << "Input y:"; cin >> y; cout << endl;

		if (move.MoveUser(x, y, &field) == 1) 
		{		
			move.MoveComputer(&field);
		}
		
		countIteration++;
	}
}

Game::~Game()
{
}
