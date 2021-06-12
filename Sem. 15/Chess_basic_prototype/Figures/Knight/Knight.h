#pragma once
#include "../FigureBase/Figure.h"

class Knight : public Figure
{

public:
	Knight(bool isWhite);
	bool canBeMoved(size_t currentX, size_t currentY, size_t destX, size_t destY) const override;
	void print() const override;
};