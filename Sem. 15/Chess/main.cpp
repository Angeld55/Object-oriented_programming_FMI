#include <iostream>
#include "ChessBoard/ChessBoard.h"
using namespace std;

//ШАХ

int main()
{
	ChessBoard c;

	c.print();

	c.move(0, 1, 2, 0);

	c.print();
}