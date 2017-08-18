#pragma once
#include "Field.h"

/*Here it is possible to use the template, I will deal with the completion of the program*/
class Options
{
public:
	Options();
	void Pause();
	void CalculateStatisticEnemy(
		Field* fieldClass,
		int* countSingleDeckShip,
		int* countDoubleDeckShip,
		int* countThreeDeckShip,
		int* countFourDeckShip
	);
	void CalculateStatisticUser(
		Field* fieldClass,
		int* countSingleDeckShip,
		int* countDoubleDeckShip,
		int* countThreeDeckShip,
		int* countFourDeckShip
	);

	void ViewStatistic(Field* field);
	~Options();
};

