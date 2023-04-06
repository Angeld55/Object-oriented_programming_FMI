#include <iostream>
#include <fstream>
#include "Rational.h"
int main()
{ 
	Rational r1(1, 2);
	Rational r2(5,10);
	Rational res = r1 + r2;
	res.rationalize();

	std::cout << res;

}
