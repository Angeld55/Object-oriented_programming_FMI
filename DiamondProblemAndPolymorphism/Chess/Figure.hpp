#include <iostream>

using namespace std;

bool isValidCoord(int xCoord, int yCoord)
{
	return  xCoord >= 0 && xCoord <= 7
		&& yCoord >= 0 && yCoord <= 7;
}

class Figure
{
public:
	Figure(int xCoord, int yCoord, bool isWhite);

	int xCoord;
	int yCoord;
	bool isWhite;
	virtual bool Move(int xCoord, int yCoord) = 0;
	virtual void Print() = 0;
	virtual ~Figure(){};
};

Figure::Figure(int xCoord, int yCoord, bool isWhite);
{
	if (isValidCoord(xCoord, yCoord))
	{
		this->xCoord = xCoord;
		this->yCoord = yCoord;
		this->isWhite = isWhite;
	}
	else
		throw "Ivalid coordinates";
}