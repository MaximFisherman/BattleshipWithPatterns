#pragma once
#include "Field.h"

class Move
{
public:
	Move();
	bool MoveUser(int x, int y, Field* fieldClass);
	bool MoveComputer(Field* fieldClass);
	~Move();
};

