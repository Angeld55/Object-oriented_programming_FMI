#pragma once

#include <iostream>
using namespace std;
class User
{
private:
	char* name;
	int age;
	void CopyFrom(const User& other);
	void Free();
public:
	//User();
	User(const char*name, int age);
	User(const User& other);
	User& operator=(const User& other);
	~User();
};
