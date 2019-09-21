#include "Figure.hpp"

class Bishop : virtual public Figure
{
public:
	Bishop(int xCoordinate, int yCoordinate, bool isWhite) :Figure(xCoordinate, yCoordinate, isWhite)
	{}

	bool Move(int xNew, int yNew);
	
	void Print();
};
bool Bishop::Move(int xNew, int yNew)
{
	if (!isValidCoord(xNew, yNew))
		return false;
	int dx = abs(xCoord - xNew);
	int dy = abs(yCoord - yNew);
	if (dx == dy)
	{
		xCoord = xNew;
		yCoord = yNew;
		return  true;
	}
	return  false;



}
void Bishop::Print()
{
	cout << 'B';
}