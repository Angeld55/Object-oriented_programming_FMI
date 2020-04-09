#pragma once
#include "Figure.hpp"
#include "Knight.hpp"
#include "Queen.hpp"

class Board
{
	Figure*** board;

public:
	Board();
	Board(const Board& other) = delete;
	Board& operator=(const Board& other) = delete;
	~Board();
	bool isEmptySquare(int x, int y) const;
	bool AddKnight(int x, int y, bool isWhite);
	bool AddQueen(int x, int y, bool isWhite);
	bool AddBishop(int x, int y, bool isWhite);
	bool AddRook(int x, int y, bool isWhite);

	void Print();

	bool MoveFigure(int xOld, int yOld, int xNew, int yNew);
	
};
Board::Board()
{
	board = new Figure**[8];
	for (int i = 0; i < 8; ++i)
		board[i] = new Figure*[8];

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; j++)
			board[i][j] = nullptr;
	}

}

Board::~Board()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			delete board[i][j];
		}
		delete[] board[i];
	}
	delete[] board;

}
bool Board::isEmptySquare(int x, int y) const
{
	return  board[x][y] == nullptr;
}

bool Board::AddKnight(int x, int y, bool isWhite)
{
	if (!isValidCoord(x, y) || !isEmptySquare(x, y))
		return false;
	board[x][y] = new Knight(x, y, isWhite);
	return true;
}
bool Board::AddQueen(int x, int y, bool isWhite)
{
	if (!isValidCoord(x, y) || !isEmptySquare(x, y))
		return false;
	board[x][y] = new Queen(x, y, isWhite);
	return true;
}
bool Board::AddBishop(int x, int y, bool isWhite)
{
	if (!isValidCoord(x, y) || !isEmptySquare(x, y))
		return false;
	board[x][y] = new Bishop(x, y, isWhite);
	return true;
}
bool Board::AddRook(int x, int y, bool isWhite)
{
	if (!isValidCoord(x, y) || !isEmptySquare(x, y))
		return false;
	board[x][y] = new Rook(x, y, isWhite);
	return true;
}

void Board::Print()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (!board[i][j])
				cout << '_';
			else
				board[i][j]->Print();

		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

bool Board::MoveFigure(int xOld, int yOld, int xNew, int yNew)
{
	if (isEmptySquare(xOld, yOld)) //Ако няма фигура, там от където искаме да преместим
		return  false;

	bool res = board[xOld][yOld]->Move(xNew, yNew); //провери дали фигурата може да се премести на съответната прозиция.
	if (!res)// ако не -> лъжа(ходът е невъзможен)
		return false;

	if (!isEmptySquare(xNew, yNew))
	{
		if (board[xOld][yOld]->isWhite ^ board[xNew][yNew]->isWhite)// ако там седи фигура от различен цвят
			delete board[xNew][yNew]; //взимаме я(трием обекта)
		else //ако фигурата която седи на новата позиция е от СЪЩИЯ цвят
		{
			board[xOld][yOld]->Move(xOld, yOld);  //връщаме обратно кординатите новата фигура. Тук би възникнал проблем, ако имаме фигурата пешка.
												  //Това е така, понеже тя няма да може да се върне назад, ако вече е преместена.
			return false;						  //За това примерно решение е, да се направи функция goBackwards.
		}
	}
	board[xNew][yNew] = board[xOld][yOld];
	board[xOld][yOld] = nullptr;
}