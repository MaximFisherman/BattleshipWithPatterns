#include "stdafx.h"
#include "Game.h"
#include <Windows.h>

Game::Game()
{
}

void Game::Run()
{
	Field& field = Field::Instance();
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
			field.clear();
			field.shipArrangement();
		}
		system("cls");
		

		cout << " Your field " << endl;
			field.ViewFieldUser();
		cout << "Field your opponent" << endl;
			field.ViewHiddenFieldEnemy();

		cout << "Input 1 for attak, input 2 for pause, input 3 for view statistic " << endl;
			cin >> action;

		countIteration++;

		if (action == 1)
		{
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

			if (move.CheckVictory(&field))
			{
				int actionFinishGame = 0;

				cout << "for replay game please press 1 and for stop game press 2" << endl;
				cin >> actionFinishGame;

				if (actionFinishGame == 1)
					countIteration = 0;

				if (actionFinishGame == 2)
					break;
			}
		}
			
		if (action == 2)
		{
			options.Pause();
		}

		if (action == 3)
		{
			options.ViewStatistic(&field);
		}
	}
}

Game::~Game()
{
}
