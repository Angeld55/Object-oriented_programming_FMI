#include "Rook.h"

Rook::Rook(bool isWhite) : Figure(isWhite, RookFigure)
{}
bool Rook::canBeMoved(size_t currentX, size_t currentY, size_t destX, size_t destY) const
{
	return currentX == destX || currentY == destY;
}
void Rook::print() const
{
	if (getIsWhite())
		std::cout << 'R';
	else
		std::cout << 'r';
}
