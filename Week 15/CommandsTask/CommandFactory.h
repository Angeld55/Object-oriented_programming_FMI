#pragma once
#include "Command.h"
class CommandFactory
{
	CommandFactory() = default;
	CommandFactory(const CommandFactory&) = delete;
	CommandFactory& operator=(const CommandFactory&) = delete;

public:
	Command* getCommand() const;
	static CommandFactory & getInstance();
};
