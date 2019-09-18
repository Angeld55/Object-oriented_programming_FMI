#include "InformaticsStudent.h"


void InformaticsStudent::CopyFrom(const InformaticsStudent& other)
{
	int len = strlen(other.name);
	name = new char[len + 1];
	strcpy(name, other.name); //copy name
	fn = other.fn; //copy fn
}
void InformaticsStudent::Free()
{
	delete[] name;
	fn = 0;
}

InformaticsStudent::InformaticsStudent()
{
	name = nullptr;
	fn = 0;
}

InformaticsStudent::InformaticsStudent(const char* name, int fn)
{
	setName(name);
	setFn(fn);
}


InformaticsStudent::InformaticsStudent(const InformaticsStudent& other)
{
	CopyFrom(other); //копирам от другия обект(няма нужда да трия памет от себе си, понже това е конструктор и обекта сега се създава)
}

InformaticsStudent& InformaticsStudent::operator=(const InformaticsStudent& other)
{
	if (this != &other)
	{
		Free(); //трия своята памет

		CopyFrom(other); // копирам от другия обект
	}
	return *this;
}

InformaticsStudent::~InformaticsStudent()
{
	Free();
}
// BIG 4 ends here

void InformaticsStudent::setName(const char* name)
{
	delete[] name; //трием данните, които са били тук.
	int len = strlen(name);
	if (hasDigits(name, len))
	{
		this->name[0] = '\0';
		return;
	}
	this->name = new char[len + 1];
	strcpy(this->name, name);


}
void InformaticsStudent::setFn(int fn)
{
	if (fn < 45000 || fn >45999)
		fn = 45000;
	this->fn = fn;
}
const InformaticsStudent::char* getName() const
{
	return name;
}
int InformaticsStudent::getFn() const
{
	return fn;
}

void printStudent()
{
	cout << name << " fn: " << fn << endl;
}
