#include <iostream>


bool isUpper(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}
bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}
bool areAllLower(const char* str)
{
	while (*str)
	{
		if (!isLower(*str))
			return false;
		str++;
	}
	return true;
}

class Student
{
private:
	char name[21];
	int age;
	bool isValidName(const char* name) const;
public:
	Student();
	Student(const char* name, int age);
	int getAge() const;
	const char* getName() const;

	void setAge(int age);
	void setName(const char* name);
};


Student::Student() : Student("Unknown", 5)
{}

Student::Student(const char* name, int age)
{
	setName(name);
	setAge(age);
}

int Student::getAge() const
{
	return age;
}

const char* Student::getName() const
{
	return name;
}
void Student::setAge(int age)
{
	if (age < 5 || age > 90)
		age = 5;
	this->age = age;
}


bool Student::isValidName(const char* name) const
{
	if (!name)
		return false;
	if (strlen(name) > 20)
		return false;
	if (!isUpper(*name))
		return false;
	if (!areAllLower(name + 1))
		return false;
	return true;
}

void Student::setName(const char* name)
{	
	if (isValidName(name))
		strcpy(this->name, name);
	else
		strcpy(this->name, "Unknown");

}



int main()
{
	Student st("Fsdfsdf", 3434);

	Student arr[3];
	std::cout << st.getName();

}
