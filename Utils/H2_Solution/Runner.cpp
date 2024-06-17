#include "Runner.h"
#include "PartialFunctionFactory.h"
#include <iostream>


void chosenValues(const PartialFunction* func)
{
	int32_t a, b;
	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;

	if (a > b)
	{
		throw std::invalid_argument("Error.");
	}

	for (int64_t i = a; i <= b; i++)
	{
		if (func->isDefined(i))
		{
			std::cout << "f(" << i << ") = " << func->operator()(i) << std::endl;
		}
	}
}

void allValues(const PartialFunction* func)
{
	std::cin.ignore(); 
	std::cout << "Press enter to output one defined value:";
	for (int64_t i = INT32_MIN; i <= INT32_MAX; i++)
	{
		if (func->isDefined(i))
		{
			std::cin.ignore();
			std::cout << "f(" << i << ") = " << func->operator()(i) << std::endl;
		}
	}

}


void run(const char* fileName)
{
	PartialFunction* function = PartialFunctionFactory::create(fileName);

	uint16_t n;
	std::cout << "Write 1 to print chosen values in [a;b] or 2 fto print all defined values: ";
	std::cin >> n;

	switch (n)
	{
	case 1:
		chosenValues(function);
		break;
	case 2:
		allValues(function);
		break;
	default:
		std::cout << "Error." << std::endl;
		break;
	}
}