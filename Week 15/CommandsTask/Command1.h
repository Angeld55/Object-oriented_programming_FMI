#pragma once
#include "Command.h"

class Command1 : public Command
{
	int N;
	const int* arr;
public:
	Command1(int* arr, int N);
	Command1(const Command1&) = delete;
	Command1& operator=(const Command1&) = delete;
	void execute(std::ostream& ofs) override;
	~Command1();
};