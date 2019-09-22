#ifndef STRING_HDR
#define STRING_HDR

#include<iostream>
#include<fstream>

const int MAX_SIZE = 1024;

class String {

private:
	char* str;
	int len;

	void CopyFrom(const String& other);
	void Free();

public:
	String();
	String(char ch);
	String(const char* str);
	String(const String& other);
	String& operator=(const String& other);
	~String();

	int getLenght() const;
	String SubString(int start);
	String SubString(int start, int end);
	int IndexOf(const String& other, int index); //return the index of the first encounter of other in the object
	int IndexOf(const char* str, int index); //reusing IndexOf(const String& other, int index)
	int CountOcurences(String str); // How many times a string is found as substring
	int GetOcurence(String str,int i); //Get if the i-th substring (count start from 1)

	const char& operator[](int index) const;
	char& operator[](int index);
	String& operator+=(const String& other); //return the concatenation of the object with other
	friend bool operator==(const String& lhs, const String& rhs); //return true if two strings are equivalent
	friend bool operator!=(const String& lhs, const String& rhs); //return true if two strings are not equivalent 
	friend std::ostream& operator<<(std::ostream& os, const String& obj);
	friend std::istream& operator>>(std::istream& is, String& obj);

	String* Split(String str);
};
const String operator+(const String& lhs, const String& rhs);


void String::CopyFrom(const String& other) {

	str = new char[strlen(other.str) + 1];
	strcpy(str, other.str);

	len = other.len;
}

void String::Free() {
	delete[] str;
}

String::String() {

	str = new char[1];
	str[0] = '\0';
	len = 0;
}

inline String::String(char ch)
{
	str = new char[2];
	str[0] = ch;
	str[1] = '\0';
	len = 1;
}

String::String(const char* str) {

	len = strlen(str);

	this->str = new char[len + 1];
	strcpy(this->str, str);
}

String::String(const String& other) {
	CopyFrom(other);
}

String& String::operator=(const String& other) {

	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}

String::~String() {
	Free();
}

int String::getLenght() const {
	return len;
}

String String::SubString(int start) {

	if (start < 0 || start > len)
		throw std::logic_error("Invalid index.\n");

	char* newStr = new char[len - start + 2];
	int j = 0;
	for (int i = start; i < len; i++) 
		newStr[j++] = str[i];
	newStr[j] = '\0';
	
	String newString(newStr);
	delete[] newStr;

	return newString;
}

String String::SubString(int start, int end) {

	if (start < 0 || start > len || end <= 0 || end > len)
		throw std::logic_error("Invalid index.\n");

	char* newStr = new char[end - start + 2];
	int j = 0;
	for (int i = start; i <= end; i++)
		newStr[j++] = str[i];
	newStr[j] = '\0';

	String newString(newStr);
	delete[] newStr;

	return newString;
}

int String::IndexOf(const String& other, int index) {

	if(index < 0)
		throw std::logic_error("Invalid index.\n");

	int iter = 0;
	for (int i = index; i <= len; i++) {

		if (iter == other.len)
			return i - other.len;
		if (str[i] != other.str[iter])
			iter = 0;
		else
			iter++;
	}
	return -1;
}

int String::IndexOf(const char* str, int index) {

	String searched(str);
	return IndexOf(searched, index);
}

int String::CountOcurences(String str)
{	
	int count = 0;
	int i = IndexOf(str,0);
	while (i!=-1)
	{
		count++;
		i = IndexOf(str, i + 1);
	}
	return count;
}

inline int String::GetOcurence(String str, int num)
{
	int count = 0;
	int i = IndexOf(str, 0);
	while (i != -1)
	{
		count++;
		if (count == num)
			return i;
		i = IndexOf(str, i + 1);
	}
	return count;
}

const char& String::operator[](int index) const {

	if(index >= len)
		throw std::out_of_range("Out of range!");
	return str[index];
}

char& String::operator[](int index) {
	return str[index];
}

String& String::operator+=(const String& other) {

	char* temp = str;
	str = new char[len + other.len + 1];
	strcpy(str, temp);
	strcat(str, other.str);
	len += other.len;
	delete[] temp;
	return *this;
}

bool operator==(const String& lhs, const String& rhs) {
	return !strcmp(lhs.str, rhs.str);
}

bool operator!=(const String& lhs, const String& rhs) {
	return strcmp(lhs.str, rhs.str);
}

std::ostream& operator<<(std::ostream& os, const String& obj) {
	return os << obj.str;
}

std::istream& operator>>(std::istream& is, String& obj) {

	char buff[MAX_SIZE];
	is.getline(buff, MAX_SIZE);
	obj.str = new char[strlen(buff) + 1];
	strcpy(obj.str, buff);

	return is;
}


const String operator+(const String& lhs, const String& rhs) {
	if (lhs.getLenght() == 0)
		return rhs;
	else if (rhs.getLenght() == 0)
		return lhs;
	return String(lhs) += rhs;
}

#endif // !STRING_HDR
