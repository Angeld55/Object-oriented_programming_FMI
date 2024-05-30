#pragma once
#include "../FigureBase/Figure.h"

class Rook : virtual public Figure
{
	
public:
	Rook(bool isWhite);
	bool canBeMoved(size_t currentX, size_t currentY, size_t destX, size_t destY) const override;
	void print() const override;
};