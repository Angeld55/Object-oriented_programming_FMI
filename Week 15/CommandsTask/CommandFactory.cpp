#include "CommandFactory.h"
#include "Command1.h"
#include "Command2.h"
#include "Command3.h"

Command* CommandFactory::getCommand() const
{
	int n;
	std::cin >> n;

	if (n == 1)
	{
		int N;
		std::cin >> N;
		int* arr = new int[N];
		for (int i = 0; i < N; i++)
			std::cin >> arr[i];
		return new Command1(arr, N); //command 1 is rensponsible for deleting the arr
	}
	else if (n == 2)
	{
		int N;
		std::cin >> N;
		char buff[1024];
		std::cin >> buff;
		char* dynArr = new char[strlen(buff) + 1];
		strcpy(dynArr, buff);
		return new Command2(dynArr, N); //command 2 is rensponsible for deleting the arr
	}
	else if (n == 3)
	{
		int a, b, c;
		std::cin >> a >> b >> c;

		return new Command3(a, b, c);
	}

}

CommandFactory& CommandFactory::getInstance()
{
	static CommandFactory factory;
	return factory;
}