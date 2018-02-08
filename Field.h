#ifndef _FIELD_H_
#define _FIELD_H_

#include "Ship.h"
#include "Definitions.h"


class Field
{
public:
	Field();
	void showField();
	void reachAction();
private:
	Ship ship1,ship2;
	void resetField();
	int field_[SIZEOFTABLE][SIZEOFTABLE];
};
#endif // !_FIELD_H_
