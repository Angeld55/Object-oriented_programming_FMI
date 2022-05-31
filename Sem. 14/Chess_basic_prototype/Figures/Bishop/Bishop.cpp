#include "Bishop.h"
#include <cmath>

Bishop::Bishop(bool isWhite) : Figure(isWhite, RookFigure)
{}
bool Bishop::canBeMoved(size_t currentX, size_t currentY, size_t destX, size_t destY) const
{
	return abs((int)currentX - (int)destX) == abs((int)currentY - (int)destY);
}
void Bishop::print() const
{
	if (getIsWhite())
		std::cout << 'B';
	else
		std::cout << 'b';
}
