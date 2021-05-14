#pragma once

class Drink
{
public:
	Drink();

	Drink(const char* name, int ml);

	Drink(const Drink& other);
	Drink& operator=(const Drink& other);
	~Drink();

	const char* getName() const;
	int getMl() const;

	void setName(const char* name);
	void setMl(int ml);

private:
	char* name;
	int ml;

	void copyFrom(const Drink& other);
	void free();

};