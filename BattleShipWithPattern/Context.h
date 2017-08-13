#pragma once
#include "ShipArrangemen.h"
class Context
{
protected: 
	ShipArrangemen* operation;
public:
	virtual ~Context();
	virtual void useStrategy(void) = 0;
	virtual void setStrategy(ShipArrangemen* st) = 0;
};

