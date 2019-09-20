#include "Expression.hpp"
int main()
{
	Expression* l = new Num(3);
	Expression* r = new Num(7);
	Expression* final1 = new Operation(l, '+', r);

	Expression* l2 = new Num(3);
	Expression* r2 = new Num(7);
	Expression* final2 = new Operation(l2, '+', r2);

	std::cout << final1->Evaluate();
	
	std::cout << AreTheSame(final1, final2);

	delete final1, final2; //Винаги трием най-големите 'Expression-и'. Те се грижат за по-малките от които са образувани.

	

}