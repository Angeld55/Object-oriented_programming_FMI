#include "Expression.hpp"
class Num : public Expression
{
	int number;
public:
	Num(int number)
	{
		this->number = number;
		type = 1;
	}
	void Print()
	{
		std::cout << number;
	}
	int Evaluate()
	{
		return number;
	}
	

};