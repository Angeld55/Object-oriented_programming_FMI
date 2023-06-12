#include "CommandExecutor.h"

void CommandExecutor::executeAll()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->execute(std::cout);
		delete arr[i];
	}
	size = 0;
}

void CommandExecutor::addCommand(Command* command)
{
	arr[size++] = command;
	if (size == 5)
		executeAll();
}

CommandExecutor::~CommandExecutor()
{
	executeAll();
}
