#pragma once

#include <iostream>

class Expression
{
public:
	virtual void Print() = 0;
	virtual int Evaluate() = 0;
	virtual ~Expression(){}
	int getType(){ return type; }
protected:
	int type; //Ако обектът е NUM, ще пазим тук 1, а ако обектът е Операция, ще пазим тук 2.
};


