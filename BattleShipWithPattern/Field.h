#pragma once
#include "stdafx.h"
#include "Context.h"
using namespace std;

class Field : public Context
{
public:
	Field();
	virtual ~Field();
	void shipArrangement();
	void useStrategy(void);
	void setStrategy(ShipArrangemen* shipArrangemenet);
};