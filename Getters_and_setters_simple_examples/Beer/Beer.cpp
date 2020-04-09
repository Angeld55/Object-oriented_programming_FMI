#include "Beer.h"

Beer::Beer(const char* mark, int ml)
{
	setMark(mark);
	setMl(ml);
}
void Beer::printAddress() const
{
	cout << this << endl;
}
void Beer::printBeer() const
{
	cout << mark << " " << ml << endl;
}
void Beer::setMl(int ml)
{
	if (ml < MINBEERML)
		ml = MINBEERML;
	else if (ml > MAXBEERML)
		ml = MAXBEERML;
	this->ml = ml;
}
void Beer::setMark(const char* mark)
{
	int len = strlen(mark);

	if (len >= 20 || len == 0) //ако ни дадат невалидна марка на бирата (стринг с дължина >= 20 )
		this->mark[0] = '\0';	//правим марката да е празния стринг 
	else
		strcpy(this->mark, mark);
}
int Beer::getMl() const 
{
	return ml;
}
const char* Beer::getMark() const
{
	return mark;
}



