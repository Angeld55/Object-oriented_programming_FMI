#pragma once
#include "../FigureBase/Figure.h"

class King : public Figure
{

public:
	King(bool isWhite);
	bool canBeMoved(size_t currentX, size_t currentY, size_t destX, size_t destY) const override;
	void print() const override;
};