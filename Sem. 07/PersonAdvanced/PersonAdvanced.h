#pragma once

class PersonAdvanced
{
public:
	PersonAdvanced(const char* name, int age);

	PersonAdvanced(const PersonAdvanced& other);
	PersonAdvanced& operator=(const PersonAdvanced& other);
	~PersonAdvanced();

	void setName(const char* name);
	void setAge(int age);

	const char* getName() const;
	int getAge() const;

	void print();

private:

	void copyFrom(const PersonAdvanced& other);
	void free();


	char* name;
	int age;
};
