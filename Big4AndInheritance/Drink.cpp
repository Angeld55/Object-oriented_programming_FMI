#include "Drink.h"


void Drink::CopyFrom(const Drink& other)
{
	int len = strlen(other.mark);
	mark = new char[len + 1];
	strcpy(mark, other.mark);

	ml = other.ml;
}
void Drink::Free()
{
	delete[] mark;
	ml = 0;
}

Drink::Drink()
{
	mark = new char[6];
	strcpy(mark, "Water");
	ml = 500;
}
Drink::Drink(const char* mark, int ml)
{
	int len = strlen(mark);
	this->mark = new char[len + 1];
	strcpy(this->mark, mark);
	
	setML(ml);

}
Drink::Drink(const Drink& other)
{
	CopyFrom(other);
}
Drink& Drink::operator=(const Drink& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Drink::~Drink()
{
	Free();
}
void Drink::setML(int ml)
{
	if (ml < 100 || ml> 1000)
		ml = 500;
	this->ml = ml;
}
int Drink::getML() const
{
	return ml;
}
const char* Drink::getMark() const
{
	return mark;
}