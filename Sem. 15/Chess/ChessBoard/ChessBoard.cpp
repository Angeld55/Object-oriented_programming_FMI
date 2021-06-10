#include "ChessBoard.h"
#include "../FigureFactory/FigureFactory.h"

ChessBoard::ChessBoard()
{
	FigureFactory factory;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		board[1][i].f = factory.createPawn(false);
		board[6][i].f = factory.createPawn(true);
	}

	board[0][0].f = factory.createRook(false);
	board[0][7].f = factory.createRook(false);

	board[7][0].f = factory.createRook(true);
	board[7][7].f = factory.createRook(true);

	
	board[0][1].f = factory.createKnight(false);
	board[0][6].f = factory.createKnight(false);
	board[7][1].f = factory.createKnight(true);
	board[7][6].f = factory.createKnight(true);

	board[0][2].f = factory.createBishop(false);
	board[0][5].f = factory.createBishop(false);
	board[7][2].f = factory.createBishop(true);
	board[7][5].f = factory.createBishop(true);

	board[0][3].f = factory.createKnig(false);
	board[0][4].f = factory.createQueen(false);
	board[7][4].f = factory.createQueen(true);
	board[7][3].f = factory.createKnig(true);
}

void ChessBoard::print() const
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j].print();
		}
		std::cout << std::endl;
	}
}