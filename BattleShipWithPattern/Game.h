#pragma once
#include "Field.h"
#include "Move.h"
#include "Options.h"

class Game :
	public Field,
	public Move,
	public Options
{
public:
	Game();
	void Run();
	~Game();
};

