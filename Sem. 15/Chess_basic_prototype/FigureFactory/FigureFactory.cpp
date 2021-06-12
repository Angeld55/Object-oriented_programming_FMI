#include "FigureFactory.h"
#include "../Figures/Bishop/Bishop.h"
#include "../Figures/King/King.h"
#include "../Figures/Knight/Knight.h"
#include "../Figures/Rook/Rook.h"
#include "../Figures/Queen/Queen.h"
#include "../Figures/Pawn/Pawn.h"

Figure* FigureFactory::createFigure(bool isWhite, FigureType type)
{

	switch (type)
	{
	case KingFigure:
		return new King(isWhite);
	case QueenFigure:
		return new Queen(isWhite);
	case KnightFigure:
		return new Knight(isWhite);
	case BishopFigure:
		return new Bishop(isWhite);
	case PawnFigure:
		return new  Pawn(isWhite);
	case RookFigure:
		return new Rook(isWhite);
	}
}