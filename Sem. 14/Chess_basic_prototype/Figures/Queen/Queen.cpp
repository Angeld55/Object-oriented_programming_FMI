#include "Queen.h"

Queen::Queen(bool isWhite) : Bishop(isWhite), Rook(isWhite), Figure(isWhite, QueenFigure)
{}

bool Queen::canBeMoved(size_t currentX, size_t currentY, size_t destX, size_t destY) const
{
	return Bishop::canBeMoved(currentX, currentY, destX, destY)
		|| Rook::canBeMoved(currentX, currentY, destX, destY);
}

void Queen::print() const
{
	if (getIsWhite())
		std::cout << 'Q';
	else
		std::cout << 'q';
}