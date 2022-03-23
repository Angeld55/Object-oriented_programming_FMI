#include <iostream>
using namespace std;

bool isSmallLetter(char ch)
{
	return ch >= 'a' && ch <= 'z';
}
bool isCapitalLetter(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}
bool containsOnlySmallChars(const char* str)
{
	size_t len = strlen(str);

	for (size_t i = 0; i < len; i++)
	{
		if (!isSmallLetter(str[i]))
			return false;
	}
	return true;
}

class Student
{
	char name[20];
	int age;

	bool isValidAge(int age)
	{
		return age >= 15 && age <= 60;
	}

	bool isValidName(const char* name)
	{
		if (name == nullptr)
			return false;

		if (strlen(name) >= 20)
			return false;

		if (!isCapitalLetter(*name))
			return false;
		return containsOnlySmallChars(name + 1);
	}

public:
	Student(const char* name, int age)
	{
		setName(name);
		setAge(age);
	}

	int getAge() const //връщаме копие!!
	{
		return age;
	}

	const char* const getName()//копие на указателя!!!
	{
		return name;
	}

	void setName(const char* name)
	{
		if (isValidName(name))
			strcpy(this->name, name);
		else
			strcpy(this->name, "Unknown");

	}
	void setAge(int age)
	{
		if (isValidAge(age))
			this->age = age;
		else
			this->age = 15;
	}
};

int main()
{
	Student s("Ivan", 33);

}
