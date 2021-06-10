#pragma once
#include <iostream>

class Figure
{
	bool isWhite;
public:
	Figure(bool isWhite) :isWhite(isWhite)
	{}
	virtual bool canBeMoved(size_t currentX, size_t currentY, size_t destX, size_t destY) const = 0;
	virtual void print() const = 0;

	bool getIsWhite() const { return isWhite; };

	virtual ~Figure(){};
};