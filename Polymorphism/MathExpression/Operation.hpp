class Operation : public Expression
{

public:
	Expression* left;
	char op;
	Expression* right;
	Operation(Expression* left, char ch, Expression* right)
	{

		this->left = left;
		op = ch;
		this->right = right;
		type = 2;

	}
	void Print()
	{
		std::cout << '(';
		left->Print();
		std::cout << op;
		right->Print();
		std::cout << ')';
	}
	int Evaluate()
	{
		int result = left->Evaluate();
		int value2 = right->Evaluate();

		if (op == '+')
			result += value2;
		else if (op == '*')
			result *= value2;
		else
			return 0; //Invalid operation
		return result;
	}
	~Operation()
	{

		delete left;
		delete right;
		op = '\0';
	}

};