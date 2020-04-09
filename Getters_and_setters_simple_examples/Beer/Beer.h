#include <iostream>
using namespace std;

const int MAXBEERML = 500;
const int MINBEERML = 330;

class Beer
{
public:
	Beer(const char* mark, int ml);
	
	void printAddress() const;

	void printBeer() const;
	void setMl(int ml);

	void setMark(const char* mark);

	int getMl() const; // const сложен тук означава, че метода не променя член-данните на класа.Съответно можем да го викаме от константни обекти

	const char* getMark() const;
	
private:

	char mark[20]; //Стринг с максимална дължина 19, понеже 1 символ ни трябва за '\0'
	int ml;
};
