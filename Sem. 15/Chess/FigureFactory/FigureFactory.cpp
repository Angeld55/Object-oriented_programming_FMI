#include "FigureFactory.h"
#include "../Figures/Bishop/Bishop.h"
#include "../Figures/King/King.h"
#include "../Figures/Knight/Knight.h"
#include "../Figures/Rook/Rook.h"
#include "../Figures/Queen/Queen.h"
#include "../Figures/Pawn/Pawn.h"

Figure* FigureFactory::createPawn(bool isWhite)
{
	return new Pawn(isWhite);
}
Figure* FigureFactory::createBishop(bool isWhite)
{
	return new Bishop(isWhite);
}
Figure* FigureFactory::createRook(bool isWhite)
{
	return new Rook(isWhite);
}
Figure* createQueen(bool isWhite)
{
	return new Queen(isWhite);
}
Figure* FigureFactory::createKnight(bool isWhite)
{
	return new Knight(isWhite);
}
Figure* FigureFactory::createKnig(bool isWhite)
{
	return new King(isWhite);
}
Figure* FigureFactory::createQueen(bool isWhite)
{
	return new Queen(isWhite);
}