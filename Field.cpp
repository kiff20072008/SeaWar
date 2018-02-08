#include "Field.h"


Field::Field():ship1(4, { 5,5 }, Ship::left), ship2(4, { 4,4 }, Ship::right)
{

	resetField();

}

void Field::showField()
{
	system("cls");
	resetField();
	for (int i = 0; i < ship1.getSize(); ++i)
	{
		field_[ship1[i].y_][ship1[i].x_] = '@';
	}
	for (int i = 0; i < SIZEOFTABLE+2; ++i)
	{
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < SIZEOFTABLE; ++i)
	{
		cout << "#";
		for (int j = 0; j < SIZEOFTABLE; ++j)
		{
			cout << (char)field_[i][j];
		}
		cout << "#";
		cout << endl;
	}
	for (int i = 0; i < SIZEOFTABLE+2; ++i)
	{
		cout << "#";
	}
	cout << endl;
}

void Field::reachAction()
{
	showField();
	char ch;
	cin >> ch;
	switch (ch)
	{
	case 'w':
	{
		ship1.moveShip(Ship::up);
		break;
	}
	case 'a':
	{
		ship1.moveShip(Ship::left);
		break;
	}
	case 's':
	{
		ship1.moveShip(Ship::down);
		break;
	}
	case 'd':
	{
		ship1.moveShip(Ship::right);
		break;
	}
	case 'q':
	{
		ship1.turnShip();
		break;
	}
	default:
	{
		break;
	}
	}
	
}

void Field::resetField()
{
	for (int i = 0; i < SIZEOFTABLE; ++i)
	{
		for (int j = 0; j < SIZEOFTABLE; ++j)
			field_[i][j] = ' ';
	}
}
