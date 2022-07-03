#pragma once
#include "../Bishop/Bishop.h"
#include "../Rook/Rook.h"

class Queen : public virtual Bishop, public virtual Rook 
{
public:
	Queen(bool isWhite);
	bool canBeMoved(size_t currentX, size_t currentY, size_t destX, size_t destY) const override;
	void print() const override;
};
