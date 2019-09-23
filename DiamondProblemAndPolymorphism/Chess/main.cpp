#include <iostream>
#include "Board.hpp"
using namespace std;

int main()
{
	while (1)
	{
		Board b;
		b.AddBishop(3, 4, true);
		b.AddKnight(2, 3, false);
		b.Print();
		b.MoveFigure(3, 4, 2, 3);
		b.Print();
	}
}
