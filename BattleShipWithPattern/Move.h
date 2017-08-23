#pragma once
#include "Field.h"

class Move
{
public:
	Move();

	template<typename FieldType>
	void Check—ondition(int x, int y, FieldType field[][SIZE_FIELD]);
	
	bool CheckVictory(Field* fieldClass);
	
	bool CheckKillShipEnemy(Field* fieldClass);
	bool CheckKillShipUser(Field* fieldClass);
	bool MoveUser(int x, int y, Field* fieldClass);
	bool MoveComputer(Field* fieldClass);
	~Move();
};

