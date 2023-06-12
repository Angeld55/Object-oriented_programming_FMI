#pragma once
#include "Command.h"

class Command3 : public Command
{
	int max;
	int mid;
	int min;
public:
	Command3(int a, int b, int c);
	void execute(std::ostream& os) override;
};