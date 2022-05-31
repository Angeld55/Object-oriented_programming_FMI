#pragma once
#include "../Figures/FigureBase/Figure.h"

const size_t BOARD_SIZE = 8;
class ChessBoard
{
	struct Cell
	{
		Figure* f = nullptr;
		Cell() = default;

		Cell(const Cell& other) = delete;
		Cell& operator=(const Cell& other) = delete;
		bool isEmpty()
		{
			return f == nullptr;
		}

		void print() const
		{
			if (f != nullptr)
				f->print();
			else
				std::cout << ' ';
		}

		~Cell()
		{
			delete f;
		}
	};
	Cell board[BOARD_SIZE][BOARD_SIZE];

public:
	ChessBoard();
	ChessBoard(const ChessBoard& other) = delete;
	ChessBoard& operator=(const ChessBoard&) = delete;

	void print() const;

	void moveFigure(size_t x, size_t y, size_t destX, size_t destY);
	
};
