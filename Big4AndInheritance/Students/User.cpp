#include "User.h"

/*
User::User(): name(nullptr),age(10)
{

}
*/

User::User(const char* name, int age)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->age = age;
}
User::User(const User& other)
{
	cout << "Copy contr of user" << endl;
	CopyFrom(other);
}
User& User::operator=(const User& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
User::~User()
{
	Free();
}
void User::CopyFrom(const User& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	age = other.age;
}
void User::Free()
{
	delete[] name;
}