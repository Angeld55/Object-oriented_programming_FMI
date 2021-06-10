#include "Pawn.h"
#include <cmath>
Pawn::Pawn(bool isWhite) : Figure(isWhite), isFirstMove(true)
{}
bool Pawn::canBeMoved(size_t currentX, size_t currentY, size_t destX, size_t destY) const
{
	/*if (currentX != destX)
		return false;

	int diff = destY - currentY;

	if (abs(diff) > 2)
		return false;

	if (diff < 0 && getIsWhite() || diff > 0 && !getIsWhite())
		return false;

	if (!abs(diff) == 2 || isFirstMove)
	{
		return true;
	}
	return false;*/
	return false;
}
void Pawn::print() const
{
	if (getIsWhite())
		std::cout << 'P';
	else
		std::cout << 'p';
}