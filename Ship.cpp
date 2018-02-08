#include "Ship.h"


Ship::Ship(int size = 1,  coord_s coord = { 0,0 }, direction_e dir = left) :size_(size), dir_(dir)
{
	if (size > 4 || size < 1)
	{
		throw std::invalid_argument("Wrong ship size");
	}
	if (coord.x_ > 10 || coord.y_ > 10 || coord.x_ < 1 || coord.y_ < 1)
	{
		throw std::invalid_argument("Wrong coordinates");
	}
	death_cell = new bool [size_];
	coord_ = new coord_s[size];
	coord_[0] = coord;
	if (!checkCoord())
	{
		throw std::invalid_argument("Wrong coordinates");
	}
	for (int i = 0; i < size_; ++i)
	{
		death_cell[i] = false;
	}
}

Ship::~Ship()
{
	delete[] coord_;
	delete[] death_cell;
}

bool Ship::isDeath()
{
	for (int i = 0; i < size_; ++i)
	{
		if (!death_cell[i])
		{
			return false;
		}
	}
	return true;
}

void Ship::turnShip()
{
	switch (dir_)
	{
	case down:
	{
		dir_ = left;
		if (!checkCoord())
		{
			dir_ = down;
		}
		break;
	}
	case left:
	{
		dir_ = up;
		if (!checkCoord())
		{
			dir_ = left;
		}
		break;
	}
	case up:
	{
		dir_ = right;
		if (!checkCoord())
		{
			dir_ = up;
		}
		break;
	}
	case right:
	{
		dir_ = down;
		if (!checkCoord())
		{
			dir_ = right;
		}
		break;
	}
	}
	updateCoord();
}

bool Ship::shoot(coord_s coord)
{
	for (int i = 0; i < size_; ++i)
	{
		if (coord.x_ == coord_[i].x_&& coord.y_ == coord_[i].y_)
		{
			death_cell[i] = true;
			return true;
		}
	}
	return false;
}

void Ship::coutInfo()
{
	cout << "Ship size - " << size_ << " direction " << dir_ << endl;
	for (int i = 0; i < (int)size_; ++i)
	{
		cout << " i coord x = " << coord_[i].x_  << " coord y " << coord_[i].y_ << endl;
	}
}

int Ship::getSize()
{
	return size_;
}

void Ship::moveShip(direction_e dir)
{
	int gorizontal_offset = ((dir == up) || (dir == down)) ? 0 : (dir == right ? 1 : -1);
	int vertikal_offset = ((dir == left) || (dir == right)) ? 0 : (dir == down ? 1 : -1);
	coord_[0] += coord_s(gorizontal_offset, vertikal_offset);
	if (!checkCoord())
	{
		coord_[0]-= coord_s(gorizontal_offset, vertikal_offset);
	}
	updateCoord();
}

Ship::coord_s Ship::operator[](int pos)
{
	if (pos > size_ || pos < 0)
	{
		throw std::logic_error("Choosed wrong position inside ship\n");
	}
	return coord_[pos];
}

bool Ship::isOverlapShip(Ship & ship)
{
	for (int i = 0; i < size_; ++i)
	{
		for (int j = 0; j < ship.getSize(); ++j)
		{
			if (coord_[i].x_ == ship[j].x_ && coord_[i].y_ == ship[j].y_)
			{
				return true;
			}
		}
	}
	return false;
}

void Ship::updateCoord()
{
	int gorizont_ = ((dir_ == up) || (dir_ == down)) ? 0 : (dir_ == right ? 1 : -1);
	int vertikal_ = ((dir_ == left) || (dir_ == right)) ? 0 : (dir_ == down ? 1 : -1);
	for (int i = 1; i < size_; ++i)
	{
		coord_[i].x_ = coord_[0].x_ +gorizont_ * i;
		coord_[i].y_ = coord_[0].y_ + vertikal_ * i; 
	}
}

bool Ship::checkCoord()
{
	updateCoord();
	for (int i = 0; i < size_; ++i)
	{
		if (coord_[i].x_ > SIZEOFTABLE-1 || coord_[i].y_ > SIZEOFTABLE-1 || coord_[i].x_ < 0 || coord_[i].y_ < 0)
			return false;
	}
	return true;
}
