#include "LogicExpressions/LogicExpr.h"

using namespace LogicExpressions;

// or |, and ^, negation !, implies >, iff -
int main()
{
	LogicExpr* expr = new Operation(new Var('p'), '|', new Negation(new Var('p'))); // p | !p
	expr->print();
	cout << " " << isTautology(expr, { 'p' }) << endl;

	LogicExpr* expr2 = new Operation(new Var('q'),'^',new Operation(new Var('p'), '^', new Negation(new Var('p')))); // q ^ (p ^ !p)
	expr2->print();
	cout << " " << isContradiction(expr2, { 'p', 'q' }) << endl;
}