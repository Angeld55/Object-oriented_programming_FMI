#include "Knight.h"
#include <cmath>

Knight::Knight(bool isWhite) : Figure(isWhite, KnightFigure)
{}
bool Knight::canBeMoved(size_t currentX, size_t currentY, size_t destX, size_t destY) const
{
	int xMovеment[] = { 1, 1, -1, -1, 2, -2, 2, -2 };
	int yMovеment[] = { 2, -2, 2, -2, 1, 1, -1, -1 };

	for (int i = 0; i < 8; i++)
	{
		if (currentX + xMovеment[i] == destX &&
			currentY + yMovеment[i] == destY)
			return true;
	}
	return false;
}

void Knight::print() const
{
	if (getIsWhite())
		std::cout << 'K';
	else
		std::cout << 'k';
}