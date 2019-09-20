#include "Animal.hpp"

class Animal
{

	String name;
public:
	Animal(String name)
	{
		this->name = name;
	}
	virtual void Roar() = 0;
	virtual Animal* clone() = 0; // Всеки наследник се копира по различен начин.
								 // За това правим тази виртуална функция и всеки наследник да окаже как се копират данните му.
	virtual ~Animal() {};

};