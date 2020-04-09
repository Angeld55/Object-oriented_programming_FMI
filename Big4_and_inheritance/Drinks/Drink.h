#pragma once
#include <iostream>

class Drink
{
private:
	char* mark;
	int ml;
	void CopyFrom(const Drink& other);
	void Free();
public:
	Drink();
	Drink(const char* mark, int ml);
	Drink(const Drink& other);
	Drink& operator=(const Drink& other);
	~Drink();
	
	void setML(int ml);
	int getML() const;
	const char* getMark() const;
};
