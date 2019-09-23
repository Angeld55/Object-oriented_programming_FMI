#pragma once
#include <iostream>
#include <string>
using namespace std;
class Animal
{

	string name;
public:
	Animal(string name)
	{
		this->name = name;
	}
	virtual void Roar() = 0;
	virtual Animal* clone() = 0; // Всеки наследник се копира по различен начин.
				     // За това правим тази виртуална функция и всеки наследник да окаже как се копират данните му.
	virtual ~Animal() {};

};
