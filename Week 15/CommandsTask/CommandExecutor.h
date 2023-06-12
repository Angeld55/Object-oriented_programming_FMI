#pragma once
#include "Command.h"

class CommandExecutor
{
	Command* arr[5];
	size_t size = 0;
	void executeAll();
public:
	CommandExecutor() = default;
	CommandExecutor(const CommandExecutor&) = delete;
	CommandExecutor& operator=(const CommandExecutor&) = delete;
	void addCommand(Command* command);
	~CommandExecutor();
};