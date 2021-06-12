#pragma once
#include "../Figures/FigureBase/Figure.h"
#include "../ConfigEnums/ConfigEnums.h"

class FigureFactory
{
public:
	static Figure* createFigure(bool isWhite, FigureType); //enum
};