#pragma once
#include "Figure.hpp"

class Rook : virtual public Figure
{

public:
	Rook(int xCoordinate, int yCoordinate, bool isWhite) :Figure(xCoordinate, yCoordinate, isWhite)
	{}
	
	bool Move(int xNew, int yNew);
	
	void Print();
	
};

bool Rook::Move(int xNew, int yNew)
{
	if (!isValidCoord(xNew, yNew))
		return false;
	if (!(xCoord == xNew ^ yCoord == yNew))
		return false;
	xCoord = xNew;
	yCoord = yNew;
	return true;
}

void Rook::Print()
{
	cout << 'R';
}