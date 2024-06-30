#pragma once
#include "../FigureBase/Figure.h"

class Pawn : public Figure
{
	bool isFirstMove;
public:
	Pawn(bool isWhite);
	bool canBeMoved(size_t currentX, size_t currentY, size_t destX, size_t destY) const override;
	void print() const override;
};
