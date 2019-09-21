#include "Figure.hpp"

class Queen : public Bishop, public Rook
{
public:
	Queen(int xCoordinate, int yCoordinate, bool isWhite) :Figure(xCoordinate, yCoordinate, isWhite), Bishop(xCoordinate, yCoordinate, isWhite), Rook(xCoordinate, yCoordinate, isWhite)
	{}
	bool Move(int xNew, int yNew);
	void Print();
};

void Queen::Print()
{
	cout << 'Q';
}
bool Queen::Move(int xNew, int yNew) // Тук сме наследили 2 функционалности. Имаме конфликт, трябва да дефинираме наша(използвайки предишните, ако искаме)
{
	bool res = Rook::Move(xNew, yNew);//Пробвай да се движиш като топ(по права линия)
	if (res) //Ако е успял - вс  е ок
		return true;
	return Bishop::Move(xNew, yNew); //Ако не си успял като топ, пробвай като офицер.
}