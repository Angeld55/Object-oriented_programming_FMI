#pragma once
#include <iostream>
class Command
{
public:
	virtual ~Command() = default;
	void virtual execute(std::ostream& ofs) = 0;
};