#pragma once
#include "Command.h"

class Command2 : public Command
{
	char* str;
	int N;
public:
	Command2(char* str, int N);
	Command2(const Command2&) = delete;
	Command2& operator=(const Command2&) = delete;
	~Command2();

	void execute(std::ostream& ofs) override;

};