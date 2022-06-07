#include "ChessBoard.h"
#include "../FigureFactory/FigureFactory.h"

ChessBoard::ChessBoard()
{
	
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		board[1][i].f = FigureFactory::createFigure(false, PawnFigure);
		board[6][i].f = FigureFactory::createFigure(true, PawnFigure);
	}

	board[0][0].f = FigureFactory::createFigure(false, RookFigure);
	board[0][7].f = FigureFactory::createFigure(false, RookFigure);

	board[7][0].f = FigureFactory::createFigure(true, RookFigure);
	board[7][7].f = FigureFactory::createFigure(true, RookFigure);

	
	board[0][1].f = FigureFactory::createFigure(false, KnightFigure);
	board[0][6].f = FigureFactory::createFigure(false, KnightFigure);
	board[7][1].f = FigureFactory::createFigure(true, KnightFigure);;
	board[7][6].f = FigureFactory::createFigure(true, KnightFigure);

	board[0][2].f = FigureFactory::createFigure(false, BishopFigure);
	board[0][5].f = FigureFactory::createFigure(false, BishopFigure);;
	board[7][2].f = FigureFactory::createFigure(true, BishopFigure);
	board[7][5].f = FigureFactory::createFigure(true, BishopFigure);

	board[0][3].f = FigureFactory::createFigure(false, KingFigure);
	board[0][4].f = FigureFactory::createFigure(false, QueenFigure);
	board[7][4].f = FigureFactory::createFigure(true, QueenFigure);
	board[7][3].f = FigureFactory::createFigure(true, KingFigure);
}

void ChessBoard::print() const
{
	std::cout << "--------" << std::endl;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j].print();
		}
		std::cout << std::endl;
	}
	std::cout << "--------" << std::endl << std::endl << std::endl;
}

void ChessBoard::moveFigure(size_t x, size_t y, size_t destX, size_t destY)
{
	
	Figure* current = board[x][y].f;

	if (current->getType() == PawnFigure)
	{
		//Some other logic.....  El'passant and other
	}
	else
	{
		if (board[x][y].f && board[x][y].f->canBeMoved(x, y, destX, destY))
		{
			delete board[destX][destY].f; //взимане на фигура
			board[destX][destY].f = board[x][y].f;
			board[x][y].f = nullptr;
		}
	}

}