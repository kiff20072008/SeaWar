#ifndef _SHIP_H_
#define _SHIP_H_
#include "Definitions.h"


class Ship
{
public:
	struct coord_s
	{
		coord_s(int x, int y) :x_(x), y_(y) {}
		coord_s() :x_(0), y_(0) {}
		int x_, y_;
	};
	enum direction_e
	{
		down,
		left,
		up,
		right
	};
	Ship(int size, coord_s coord, direction_e dir );
	~Ship();
	bool isDeath();
	void turnShip();
	bool shoot(coord_s coord);
	void coutInfo();
	int getSize();
	void moveShip(direction_e dir);
	coord_s operator[](int pos);
	bool isOverlapShip(Ship &ship);
private:
	int size_;
	coord_s *coord_;
	direction_e dir_;
	bool *death_cell;
	void updateCoord();
	bool checkCoord();
};

Ship::coord_s operator+(Ship::coord_s lhs, Ship::coord_s rhs);
Ship::coord_s operator-(Ship::coord_s lhs, Ship::coord_s rhs);
Ship::coord_s& operator+=(Ship::coord_s &lhs, Ship::coord_s rhs);
Ship::coord_s& operator-=(Ship::coord_s &lhs, Ship::coord_s rhs);
bool operator<(Ship::coord_s &lhs, Ship::coord_s &rhs);
bool operator>(Ship::coord_s &lhs, Ship::coord_s &rhs);

#endif