#pragma once
#include "../Figures/FigureBase/Figure.h"

class FigureFactory
{
public:
	Figure* createPawn(bool isWhite);
	Figure* createBishop(bool isWhite);
	Figure* createRook(bool isWhite);
	Figure* createQueen(bool isWhite);
	Figure* createKnight(bool isWhite);
	Figure* createKnig(bool isWhite);
};