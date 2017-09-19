#pragma once
#include "stdafx.h"
#include "StateField.h"

using namespace std;

class Field
{
	class StateField *current;
public:
	Field();
	char fieldUser[SIZE_FIELD][SIZE_FIELD];
	char fieldEnemy[SIZE_FIELD][SIZE_FIELD];
	char hiddenFieldEnemy[SIZE_FIELD][SIZE_FIELD];

	vector<int> CoordinateSingleDeckShip;
	vector<int> CoordinateDoubleDeckShip;
	vector<int> CoordinateThreeDeckShip;
	vector<int> CoordinateFourDeckShip;

	vector<int> CoordinateSingleDeckShipEnemy;
	vector<int> CoordinateDoubleDeckShipEnemy;
	vector<int> CoordinateThreeDeckShipEnemy;
	vector<int> CoordinateFourDeckShipEnemy;

	void setCurrent(StateField *s);

	void setSingleDeckShip();
	void setDoubleDeckShip();
	void setThreeDeckShip();
	void setFourDeckShip();

	void ViewFieldUser();
	void ViewFieldEnemy();
	void ViewHiddenFieldEnemy();

	void shipArrangement();
	
	void clear();
	virtual ~Field();
};