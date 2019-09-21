#include "Figure.hpp"

class Knight : public Figure
{
public:
	Knight(int xCoordinate, int yCoordinate, bool isWhite) :Figure(xCoordinate, yCoordinate, isWhite)
	{}
	
	bool Move(int xNew, int yNew);
	
	void Print();
};
bool Knight::Move(int xNew, int yNew)
{
	if (!isValidCoord(xNew, yNew))
		return false;
	int possibleX[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
	int possibleY[] = { 2, -2, 2, -2, 1, -1, 1, -1 };
	for (int i = 0; i < 8; ++i)
	{
		if (xNew == xCoord + possibleX[i]
			&& yNew == yCoord + possibleY[i])
		{
			xCoord = xNew;
			yCoord = yNew;
			return  true;
		}

	}
	return false;

}

void Knight::Print()
{
	cout << 'K';
}