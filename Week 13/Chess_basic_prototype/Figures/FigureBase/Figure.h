#pragma once
#include <iostream>
#include "../../ConfigEnums/ConfigEnums.h"

class Figure
{
	bool isWhite;
	FigureType type;

public:
	Figure(bool isWhite, FigureType type) :isWhite(isWhite), type(type)
	{}

	virtual bool canBeMoved(size_t currentX, size_t currentY, size_t destX, size_t destY) const = 0;
	virtual void print() const = 0;

	bool getIsWhite() const { return isWhite; };
	FigureType getType() const { return type; }

	virtual ~Figure() = default;
};