#include <iostream>
#include <cstring>
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
constexpr int NAME_MAX_LEN = 20;
constexpr int NAME_MIN_LEN = 2;
constexpr int AGE_MIN = 5;
constexpr int AGE_MAX = 90;

class Student
{
	char name[NAME_MAX_LEN + 1] = "Unknown";
	int age = AGE_MIN;

	bool isValidAge(int age)
	{
		return age >= AGE_MIN && age <= AGE_MAX;
	}

	bool isValidName(const char* name)
	{
		if (name == nullptr)
			return false;
        size_t nameLen = strlen(name);
		if (nameLen <= NAME_MIN_LEN || nameLen >= NAME_MAX_LEN)
			return false;
		if (!isCapitalLetter(*name))
			return false;
		return containsOnlySmallChars(name + 1);
	}

public:
    Student() = default;
    
	Student(const char* name, int age)
	{
		setName(name);
		setAge(age);
	}

	int getAge() const //връщаме копие!!
	{
		return age;
	}

	const char* getName() const //копие на указателя!!!
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
