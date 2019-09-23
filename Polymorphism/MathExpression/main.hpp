#include "Expression.hpp"
#include "Num.hpp"
#include "Operation.hpp"
bool AreTheSame(Expression* left, Expression* right);
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
bool AreTheSame(Expression* left, Expression* right)
{
	if (left->getType() != right->getType())//гледаме дали не са от раличен тип (едното да е опрация,другото да е число)
		return false; //очевидно са различни тогава

	if (left->getType() == 1) //ако двете са числа
	{
		Num* l = (Num*)left; //Конвертираме пойнтерите
		Num* r = (Num*)right;
		return l->getNum() == r->getNum(); //сравняваме стойностите
	}
	else //Ако двете са операции
	{
		Operation* l = (Operation*)left;
		Operation* r = (Operation*)right;
		return  (l->op == l->op) && AreTheSame(l->left, r->left) && AreTheSame(l->right, r->right);
		//гледаме дали знаците на опрациите съвпадат, дали левите страни съвпадат и дали десните страни съвпадат.
	}

}
