#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

namespace LogicExpressions
{

	const int ENGLISH_ALPHABET_SIZE = 26;
	struct BooleanInterpretation
	{
		bool values[ENGLISH_ALPHABET_SIZE];
		BooleanInterpretation()
		{
			for (int i = 0; i < ENGLISH_ALPHABET_SIZE; i++)
				values[i] = false;
		}
		void setVarValue(char v, bool value)
		{
			values[v - 'a'] = value;
		}

		bool getVarValue(char v) const
		{
			return values[v - 'a'];
		}
	};

	struct LogicExpr
	{
		virtual void print() const = 0;
		LogicExpr() = default;
		LogicExpr(const LogicExpr&) = delete;
		LogicExpr& operator=(const LogicExpr& other) = delete;

		virtual bool evaluate(const BooleanInterpretation& interpret) const = 0;
		virtual ~LogicExpr(){};
	};
	struct Var : public LogicExpr
	{
		char v;
		Var(char v) :v(v){}

		void print() const
		{
			cout << v;
		}

		bool evaluate(const BooleanInterpretation& interpret) const
		{
			return interpret.getVarValue(v);
		}
	};
	struct Operation : public LogicExpr
	{
		LogicExpr* left;
		char op;
		LogicExpr* right;

		Operation(LogicExpr* lhs, char op, LogicExpr* rhs) : left(lhs), op(op), right(rhs){}

		void print() const
		{
			cout << "(";
			left->print();
			cout << op;
			right->print();
			cout << ")";
		}
		~Operation()
		{
			delete left;
			delete right;
		}

		bool evaluate(const BooleanInterpretation& interpret) const
		{
			bool res1 = left->evaluate(interpret);
			bool res2 = right->evaluate(interpret);

			switch (op)
			{
			case '^':return res1 && res2;
			case '|':return res1 || res2;
			case '>':return !res1 || res2;
			case '+': return res1 ^ res2;
			case '-': return (res1 && res2) || (!res1 && !res2);
			}

		}
	};
	struct Negation : public LogicExpr
	{
		LogicExpr* current;
		Negation(LogicExpr* current) :current(current){}

		void print() const
		{
			cout << "!(";
			current->print();
			cout << ")";
		}
		~Negation()
		{
			delete current;
		}

		bool evaluate(const BooleanInterpretation& interpret) const
		{
			bool result = current->evaluate(interpret);
			return !result;
		}
	};

	BooleanInterpretation convertNumberToInterpretation(size_t n, const std::vector<char>& vars)
	{
		BooleanInterpretation current;
		for (int i = vars.size() - 1; i >= 0; i--, n/=2)
			current.setVarValue(vars[i], n % 2);

		return std::move(current);
	}

	bool CheckValues(const LogicExpr* expr, const std::vector<char>& vars, bool value)
	{
		size_t checksCounts = 1 << vars.size();

		for (int i = 0; i < checksCounts; i++)
		{
			BooleanInterpretation currentInterpret = convertNumberToInterpretation(i, vars);
		
			if (expr->evaluate(currentInterpret) != value)
				return false;
		}
		return true;
	}

	bool isTautology(const LogicExpr* expr, const std::vector<char>& vars)
	{
		return CheckValues(expr, vars, true);
	}

	bool isContradiction(const LogicExpr* expr, const std::vector<char>& vars)
	{
		return CheckValues(expr, vars, false);
	}
}

