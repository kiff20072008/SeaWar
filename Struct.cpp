#include "Ship.h"


Ship::coord_s operator+(Ship::coord_s lhs, Ship::coord_s rhs)
{
	return Ship::coord_s(lhs.x_ + rhs.x_, lhs.y_ + rhs.y_);
}
Ship::coord_s operator-(Ship::coord_s lhs, Ship::coord_s rhs)
{
	return Ship::coord_s(lhs.x_ - rhs.x_, lhs.y_ - rhs.y_);
}
Ship::coord_s& operator+=(Ship::coord_s& lhs, Ship::coord_s rhs)
{
	lhs = lhs + rhs;
	return lhs ;
}
Ship::coord_s& operator-=(Ship::coord_s & lhs, Ship::coord_s rhs)
{
	lhs = lhs - rhs;
	return lhs;
}
bool operator<(Ship::coord_s &lhs, Ship::coord_s &rhs)
{
	return (lhs.x_ < rhs.x_ || lhs.y_ < rhs.y_);
}
bool operator>(Ship::coord_s &lhs, Ship::coord_s &rhs)
{
	return !(lhs < rhs);
}