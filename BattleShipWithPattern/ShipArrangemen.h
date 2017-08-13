#pragma once

class ShipArrangemen
{
public:
	virtual ~ShipArrangemen() {};
	bool PlacingShip(
		int         size,
		bool        isHoriz,
		int         rowTop,
		int         colLeft,
		char  field[][SIZE_FIELD]
	);
	virtual void use(void) = 0;
};

